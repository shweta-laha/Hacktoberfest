def is_leap(year):
    leap = False
    
    if year%4!=0: return leap;
    if year%100!=0: 
        leap=True
        return leap
    if year%400==0:
        leap= True
        return leap;
    
    return leap

year = int(raw_input())
print is_leap(year)
