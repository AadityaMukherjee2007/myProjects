import time
import requests
from bs4 import BeautifulSoup

urls = [
    'https://www.moneycontrol.com/india/stockpricequote/ironsteel/tatasteel/TIS',
    'https://www.moneycontrol.com/india/stockpricequote/computers-software/tataconsultancyservices/TCS',
    'https://www.moneycontrol.com/india/stockpricequote/refineries/relianceindustries/RI',
    'https://www.moneycontrol.com/india/stockpricequote/banks-private-sector/icicibank/ICI02',
    'https://www.moneycontrol.com/india/stockpricequote/computers-software/infosys/IT'
]

while True:
    try:
        for url in urls:
            page = requests.get(url)
            scrape = BeautifulSoup(page.text, 'html.parser')

            company = scrape.find('div', {'class': 'inid_name'}).find('h1').text
            price = scrape.find('div', {'class': 'inprice1 bsecp'}).text
            change = scrape.find('div', {'id': 'nsechange'}).text

            print(company, price, change, '\n')
        print('\n')
        time.sleep(5)
    except KeyboardInterrupt:
        print('Program Terminated...')
        exit()