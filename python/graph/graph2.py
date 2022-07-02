import matplotlib.pyplot as plt

x, y = [], []

i = 1
while i <= 5:
	if i > 1 : 
		print()

	x.append(input("x: "))
	y.append(input("y: "))
	i += 1

plt.bar(x, y, color = "orange", label = "Line1")
plt.scatter(x, y, color = "blue", label = "Line1")
plt.plot(x, y, color = "g", label = "Line1")
plt.xlabel("x - axis")
plt.ylabel("y - axis")
plt.title("Graph2")
#plt.legend()
plt.show()