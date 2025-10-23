def ctof(c):
	f = ((9 * c) / 5) + 32
	return f
	
def ftoc(f):
	c = (5 / 9) * (f - 32)
	return c

def ktoc(k):
	c = k - 273.15
	return c
	
def ctok(c):
	k = 273.15 + c
	return k

print("Temperature Conversion: ")

while True:
	print('\nChoice: \n0 --> exit\n1 --> Celcius to Fahrenheit\n2 --> Fahrenheit to Celcius\n3 --> Kelvin to Celcius\n4 --> Celcius to Kelvin\n')

	ch = int(input('Enter choice: '))
	if ch == 0:
		exit()
	elif ch == 1:
		temp = float(input('Enter Temperature: '))
		ans = ctof(temp)
		print(str(ans) + ' ⁰F')
	elif ch == 2:
		temp = float(input('Enter Temperature: '))
		ans = ftoc(temp)
		print(str(ans) + ' ⁰C')
	elif ch == 3:
		temp = float(input('Enter Temperature: '))
		ans = ktoc(temp)
		print(str(ans) + ' ⁰C')
	elif ch == 4:
		temp = float(input('Enter Temperature: '))
		ans = ctok(temp)
		print(str(ans) + ' K')
	else:
		print('Enter proper input!')
