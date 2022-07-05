import random as rd
import matplotlib.pyplot as plt

def prob(tests):
	global h, t, heads, tails, Tests
	h, t = 0, 0
	Tests = tests
	for x in range(0, tests):
		toss = rd.randint(1, 3)
		if toss == 1:
			h += 1
		else:
			t += 1

	heads = (h / tests) * 100
	tails = (t / tests) * 100

	print("\nProbability: ")
	print("Heads: " + str(heads) + "%")
	print("Tails: " + str(tails) + "%")

def plot():
	label = ["Heads", "Tails"]
	x = [heads, tails]
	plt.ylim(top = 100)
	plt.bar(label, x, width = 0.3)
	plt.xlabel("Coin Side")
	plt.ylabel("Probability(%)")
	plt.title("Coin Toss")
	plt.show()


prob(int(input("Test: ")))
plot()