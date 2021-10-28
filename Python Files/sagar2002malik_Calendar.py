import calendar
import pyttsx3

def date():
    pyttsx3.speak("Enter the year")
    y = int(input("Input the year : "))
    return calendar.calendar(y)

if __name__ == "__main__":
    while True:
        print(date())
