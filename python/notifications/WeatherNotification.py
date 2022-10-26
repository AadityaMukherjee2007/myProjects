import requests, playsound
from time import sleep
from bs4 import BeautifulSoup
from plyer import notification

url1 = "https://www.google.com/search?q=weatherkolkata"
url2 = "https://mausam.imd.gov.in/kolkata"
url3 =  "https://www.airnow.gov/?city=Kolkata&country=IND"

page1 = requests.get(url1)
fetch1 = BeautifulSoup(page1.text, 'html.parser')
#print(fetch1.prettify())

page2 = requests.get(url2)
fetch2 = BeautifulSoup(page2.text, 'html.parser')
#print(fetch2.prettify())
'''
page3 = requests.get(url3)
fetch3 = BeautifulSoup(page3.text, 'html.parser')
print(fetch3.prettify())
#aqi = fetch3.find('div', {'class': 'aqi'}).text

print(aqi)
'''

time = fetch1.find('div', {'class': 'BNeawe tAd8D AP7Wnd'}).text.split()[1]
date = fetch1.find('div', {'class': 'BNeawe tAd8D AP7Wnd'}).text.split()[0]
loc = fetch1.find('span', {'class': 'BNeawe tAd8D AP7Wnd'}).text
temp = fetch1.find('div', {'class': 'BNeawe iBp4i AP7Wnd'}).text
windDir = fetch2.find('p', {'class': 'wind'}).text.split()[0]
windSpd = fetch2.find('p', {'class': 'wind'}).text.split()[1]
humidity = fetch2.find('p', {'class': 'minmax'}).text
'''aqi = fetch3.find('text', {'class': 'value-text'}).text
print(aqi)'''

weatherData = "Time: " + time + "\nDate: " + date + "\nLocation: " + loc + "\nTemperature: " + temp + "\nHumidity: " + humidity + "\nWind Direction: " + windDir + "\nWind Speed: " + windSpd #+ "AQI: " + aqi

while True:
	notification.notify(
		title = "Weather Update",
		message = weatherData,
		timeout = 10
	)
	playsound.playsound("./not_1.wav")
	sleep(60)