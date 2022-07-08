import pandas as pd
import matplotlib.pyplot as plt

apple = pd.read_csv("./appl_1980_2014.csv")

apple['Open'].plot()
apple['High'].plot()
apple['Low'].plot()
apple['Close'].plot()
apple['Adj Close'].plot()

plt.plot(apple['Date'])

plt.legend()
plt.show()