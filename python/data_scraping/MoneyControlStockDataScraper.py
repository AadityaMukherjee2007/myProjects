import requests, csv
from os import path
from datetime import date
from bs4 import BeautifulSoup

if path.exists('dateToday.txt') == False:
    f = open('dateToday.txt', 'x')
else:
    f = open('dateToday.txt', 'r')
    if f.read() == str(date.today()):
        exit()

"""urls = []

while True:
    url = input("Enter URL: ")
    if url == "":
        break
    else:
        try:
            check = requests.get(url)
        except:
            print("Enter proper url.")
            continue
        urls.append(url)
"""

urls = [
    'https://www.moneycontrol.com/india/stockpricequote/ironsteel/tatasteel/TIS',
    'https://www.moneycontrol.com/india/stockpricequote/computers-software/tataconsultancyservices/TCS',
    'https://www.moneycontrol.com/india/stockpricequote/refineries/relianceindustries/RI',
    'https://www.moneycontrol.com/india/stockpricequote/banks-private-sector/icicibank/ICI02',
    'https://www.moneycontrol.com/india/stockpricequote/computers-software/infosys/IT',
    'https://www.moneycontrol.com/india/stockpricequote/diversified/itc/ITC'
]


file = open('stockPrices.csv', 'a', newline = '')
writer = csv.writer(file)
writer.writerow(['Date', 'Company', 'Price', 'Change'])

for url in urls:
    page = requests.get(url)
    scrape = BeautifulSoup(page.text, 'html.parser')

    company = scrape.find('div', {'class': 'inid_name'}).find('h1').text
    price = scrape.find('div', {'class': 'inprice1 bsecp'}).text
    change = scrape.find('div', {'id': 'nsechange'}).text

    writer.writerow([date.today(), company, price, change])
    print(company, price, change)
file.close()

with open('dateToday.txt', 'w') as f:
    f.write(str(date.today()))