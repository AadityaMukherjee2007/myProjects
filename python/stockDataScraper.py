import requests
from bs4 import BeautifulSoup
import time

urls = [
	'https://www.investing.com/equities/apple-computer-inc',
	'https://www.investing.com/equities/microsoft-corp',
	'https://www.investing.com/equities/nike',
	'https://www.investing.com/equities/amazon-com-inc',
	'https://www.investing.com/equities/google-inc',
	'https://www.investing.com/equities/tesla-motors',
	'https://www.investing.com/equities/nvidia-corp',
	'https://www.investing.com/equities/intel-corp',
	'https://www.investing.com/equities/adv-micro-device',
	'https://www.investing.com/equities/netflix,-inc.'
	]

#print(page.status_code)

while True:
	for url in urls:
		page = requests.get(url)
		scrape = BeautifulSoup(page.text, 'html.parser')

		company = scrape.find('h1', {'class' : 'text-2xl font-semibold instrument-header_title__GTWDv mobile:mb-2'}).text
		price = scrape.find('div', {'class' : 'instrument-price_instrument-price__3uw25 flex items-end flex-wrap font-bold'}).find_all('span')[0].text
		change = scrape.find('div', {'class' : 'instrument-price_instrument-price__3uw25 flex items-end flex-wrap font-bold'}).find_all('span')[1].text
		changePercent = scrape.find('div', {'class' : 'instrument-price_instrument-price__3uw25 flex items-end flex-wrap font-bold'}).find_all('span')[2].text

		#print("Loading: " + url)
		print(company, price, change, changePercent)

	print('\n\n')
	time.sleep(5)