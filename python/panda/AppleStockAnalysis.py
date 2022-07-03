import pandas as pd
import matplotlib.pyplot as plt

apple = pd.read_csv("./appl_1980_2014.csv")
apple.plot(x = "Date", y = "Volume")
plt.show()