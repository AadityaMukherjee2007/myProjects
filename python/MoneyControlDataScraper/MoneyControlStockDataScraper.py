import requests, csv
from os import path
from datetime import date
from bs4 import BeautifulSoup

if path.exists('dateToday.txt') == False:
    f = open('dateToday.txt', 'x')
else:
    f = open('dateToday.txt', 'r')
    if f.read() == str(date.today()):
        #exit()
        pass



if path.exists('stockUrl.txt') == False:
    while True:
        f = open('stockUrl.txt', 'a')
        try:
            url = input("URL: ")
            if url == "":
                print('URLs stored!')
                f.close()
                break
            else:
                try:
                    check = requests.get(url)
                except:
                    print("Enter proper url.")
                    continue
                f.write(url)
                f.write("\n")
        except KeyboardInterrupt:
            print('URLs stored!')
            f.close()
            break



f = open('stockUrl.txt', 'r')
urls = f.read().splitlines()

if path.exists('stockPrices.csv') == False:
    file = open('stockPrices.csv', 'w')
    writer = csv.writer(file)
    writer.writerow(['Date', 'Company', 'Price', 'Change'])
else:
    file = open('stockPrices.csv', 'a')
    writer = csv.writer(file)


try:
    for url in urls:
        page = requests.get(url)
        scrape = BeautifulSoup(page.text, 'html.parser')

        company = scrape.find('div', {'class': 'inid_name'}).find('h1').text
        price = scrape.find('div', {'class': 'inprice1 bsecp'}).text
        change = scrape.find('div', {'id': 'nsechange'}).text

        writer.writerow([date.today(), company, price, change])
        print(company, price, change)
    file.close()
finally:
    print("Written to file successfully!")


with open('dateToday.txt', 'w') as dateFile:
    dateFile.write(str(date.today()))
    dateFile.close()