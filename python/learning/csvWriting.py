import csv, os

if os.path.exists('test.csv') == False:
	file = open('test.csv', 'w', newline='')
else:
	file = open('test.csv', 'a', newline='')

writer = csv.writer(file)
head = ['Name', 'Roll']

data = []

name = input("Name: ")
roll = int(input("Roll: "))

data.append(name)
data.append(roll)

writer.writerow(head)
writer.writerow(data)
file.close()