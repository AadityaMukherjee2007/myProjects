from bs4 import BeautifulSoup
import requests
import tkinter as tk

usdInrVal = ''

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
		Usd = str(float(inrIn.get()) / usdInrVal)
		print(Usd)
		usdIn.delete(0, "end")
		usdIn.insert(0, Usd)

def UsdToInr():
	if usdIn.get() != '':
		Inr = str(float(usdIn.get()) * usdInrVal)
		print(Inr)
		inrIn.delete(0, "end")
		inrIn.insert(0, Inr)

def main():
	main = tk.Tk()
	main.title('INR-USD')
	main.resizable(False, False)
	main.geometry('250x130')

	global inrIn, usdIn

	inr = tk.Label(main, text='INR : ')
	usd = tk.Label(main, text='USD : ')
	inrIn = tk.Entry(main)
	usdIn = tk.Entry(main)
	convInrToUsd = tk.Button(main, text='INR-USD', command=InrToUsd)
	convUsdToInr = tk.Button(main, text='USD-INR', command=UsdToInr)

	inrIn.place(x = 50, y = 10)
	usdIn.place(x = 50, y = 40)
	inr.place(x = 10, y = 10)
	usd.place(x = 10, y = 40)
	convInrToUsd.place(x = 20, y = 80)
	convUsdToInr.place(x = 150, y = 80)

	main.mainloop()

main()