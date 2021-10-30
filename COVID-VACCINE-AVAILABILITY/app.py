import os
import time
import requests
import numpy as np
import pandas as pd
from datetime import datetime, date, timedelta
import streamlit as st
from fake_useragent import UserAgent

# Application
st.markdown("<h1 style='text-align: center; color: red;'>CoWin Availability Status</h1>", unsafe_allow_html=True)
pin = st.text_input("PIN Code")
start_date = st.date_input("Lookup Start Date")
end_date = st.date_input("Lookup End Date")
fee = st.selectbox('Fee Type',('Paid', 'Free', 'both'))
age = st.selectbox('Age limit',('18-45', '45+'))

if age == '18-45':
    age_select = 18
else:
    age_select = 45

# Convert time function
def convert_time(date_str):
      time_value = datetime.strptime(date_str, '%I:%M%p').time()
      return time_value
    

# Get centers/hospitals
def get_centers(read_json, fee_type: str, age_limit: int, start_time: datetime, finish_time: datetime, availability:str):
      """
      @param read_json: Json variable
      @availability: If vaccines are in stock
      @fee_type: Free or paid
      @age_limit: 18 or 45
      @start_time: Time for vaccine to start
      @finish_time: Time for vaccine to end
      """

      centers = pd.DataFrame(read_json.get('centers'))

      list_sessions = []
      for j, row in centers.iterrows():
        session = pd.DataFrame(row['sessions'][0])
        session['center_id'] = centers.loc[j, 'center_id']
        list_sessions.append(session)

      sessions = pd.concat(list_sessions, ignore_index=True)
      session_center = centers.merge(sessions, on='center_id')
      session_center.drop(columns=['sessions', 'session_id'], inplace=True)

      if availability == 'stock':
        session_center = session_center[session_center['available_capacity'] > 0]

      if fee_type == 'Paid':
        session_center = session_center[session_center['fee_type'] == 'Paid']
      elif fee_type == 'Free':
        session_center = session_center[session_center['fee_type'] == 'Free']

      if age_limit == 18:
        session_center = session_center[session_center['min_age_limit'] == 18]
      elif age_limit == 45:
        session_center = session_center[session_center['min_age_limit'] == 45]

      if not session_center.empty:
        session_center[['start', 'finish']] = session_center['slots'].str.split('-', expand=True)
        session_center['start'] = session_center['start'].apply(lambda x: convert_time(x))
        session_center['finish'] = session_center['finish'].apply(lambda x: convert_time(x))

        if start_time and finish_time:
          session_center = session_center[(session_center['start'] >= start_time) & (session_center['start'] <= finish_time)]
        elif start_time:
          session_center = session_center[session_center['start'] >= start_time]
        elif finish_time:
          session_center = session_center[session_center['start'] <= finish_time]

      session_center.reset_index(drop=True, inplace=True)
      return session_center
    

if st.checkbox("Submit"):
    start_date = start_date.strftime("%Y-%m-%d")
    end_date = end_date.strftime("%Y-%m-%d")
    pincodes = int(pin)
    availability = 'all'
    fee_type = fee
    age_limit = age_select
    start = None
    end = None

    lookup_start_date = date(int(start_date[0:4]), int(start_date[5:7]), int(start_date[8:]))  # YYYY, m, dd
    lookup_end_date = date(int(end_date[0:4]), int(end_date[5:7]), int(end_date[8:]))  # YYYY, m, dd

    if start:
        start_time = datetime.strptime(start, '%I:%M%p').time()
    else:
        start_time = start

    if end:
        finish_time = datetime.strptime(end, '%I:%M%p').time()
    else:
        finish_time = end
        
    delta = (lookup_end_date - lookup_start_date).days + 1
    range_dates = [lookup_start_date + timedelta(days=day) for day in range(delta)]
    date_range = [x.strftime('%d-%m-%Y') for x in range_dates]
    
    ua = UserAgent()
    header = {'User-Agent':str(ua.chrome)}
    data_list = []
    for date in date_range:
        response = requests.get(f"https://cdn-api.co-vin.in/api/v2/appointment/sessions/public/calendarByPin?pincode={pincodes}&date={date}", headers=header)
        read_json = response.json()
 
        if 'Forbidden' in read_json.values():
          print(f'Message is forbidden, fetch is being blocked for PIN: {pincodes} and Date: {date} - {read_json}')
        elif [] in read_json.values():
          print(f'Fetch successful, no vaccination centres available for PIN: {pincodes} and Date: {date}  - {read_json}')
        else:
            try:
                data = get_centers(read_json, fee_type, age_limit, start_time, finish_time, availability)
                data_list.append(data)
            except ValueError:
                st.warning(f'Invalid PIN')
                os._exit(1)

    try:
        data_set = pd.concat(data_list)
        data_set.sort_values(['available_capacity', 'min_age_limit'], ascending=[False, True], inplace=True, ignore_index=True)
        data_set1 = data_set[['center_id', 'name', 'slots', 'available_capacity']]
        data_set1.columns = ['Center ID', 'Name', 'Slots', 'Availability']

        try:
            st.write(f"District: {data_set['district_name'][0]}")
            st.dataframe(data_set1.assign(hack='').set_index('hack'), width=4000, height=600)
        except KeyError:
            st.warning(f'No vaccination centres available for PIN: {pincodes} on given dates')
    except ValueError:
        st.warning(f'No vaccination centres available for PIN: {pincodes} on given dates')
