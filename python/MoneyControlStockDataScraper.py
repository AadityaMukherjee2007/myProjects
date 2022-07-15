import time
import requests
from bs4 import BeautifulSoup

urls = []

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


"""urls = [
    'https://www.moneycontrol.com/india/stockpricequote/ironsteel/tatasteel/TIS',
    'https://www.moneycontrol.com/india/stockpricequote/computers-software/tataconsultancyservices/TCS',
    'https://www.moneycontrol.com/india/stockpricequote/refineries/relianceindustries/RI',
    'https://www.moneycontrol.com/india/stockpricequote/banks-private-sector/icicibank/ICI02',
    'https://www.moneycontrol.com/india/stockpricequote/computers-software/infosys/IT',
    'https://www.moneycontrol.com/india/stockpricequote/diversified/itc/ITC'
]
"""
while True:
    try:
        for url in urls:
            page = requests.get(url)
            scrape = BeautifulSoup(page.text, 'html.parser')

            company = scrape.find('div', {'class': 'inid_name'}).find('h1').text
            price = scrape.find('div', {'class': 'inprice1 bsecp'}).text
            change = scrape.find('div', {'id': 'nsechange'}).text

            print(company, price, change)
        print()
        time.sleep(5)
    except KeyboardInterrupt:
        print('Program Terminated...')
        exit()