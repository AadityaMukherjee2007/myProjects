from bs4 import BeautifulSoup
import requests
import tkinter as tk

usdInrVal, INR, USD = '', '', ''

url = 'https://in.investing.com/currencies/usd-inr'
try:
	page = requests.get(url)
	val = BeautifulSoup(page.text, 'html.parser')
	usdInrVal = val.find('bdo', {'class': 'last-price-value js-streamable-element'}).text
	with open('usdInrVal.txt', 'w') as f:
		f.write(usdInrVal)
except:
	print('No internet\nUsing previous data...')
	with open('usdInrVal.txt', 'r') as f:
		usdInrVal = f.read()
finally:
	usdInrVal = float(usdInrVal)

def InrToUsd():
	if inrIn.get() != '':
		Usd = str(format(float(inrIn.get()), '.2f') / usdInrVal)
		print(Usd)
		usdIn.config(text=Usd)

def UsdToInr():
	if usdIn.get() != '':
		Inr = str(format(float(usdIn.get()), '.2f') * usdInrVal)
		print(Inr)
		inrIn.config(text=Inr)



main = tk.Tk()
main.title('INR-USD')
main.resizable(False, False)
main.geometry('250x130')

global inrIn, usdIn

inr = tk.Label(main, text='INR : ')
usd = tk.Label(main, text='USD : ')
inrIn = tk.Entry(main, text = INR)
usdIn = tk.Entry(main, text = USD)
convInrToUsd = tk.Button(main, text='INR-USD', command=InrToUsd)
convUsdToInr = tk.Button(main, text='USD-INR', command=UsdToInr)

inrIn.place(x = 50, y = 10)
usdIn.place(x = 50, y = 40)
inr.place(x = 10, y = 10)
usd.place(x = 10, y = 40)
convInrToUsd.place(x = 20, y = 80)
convUsdToInr.place(x = 100, y = 80)

main.mainloop()