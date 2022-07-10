import pandas as pd
import matplotlib.pyplot as plt

apple = pd.read_csv("./appl_1980_2014.csv")
head = ["Open", "High", "Low", "Close", "Volume", "Adj Close"]
apple.plot(x = "Date", y = head)
plt.show()