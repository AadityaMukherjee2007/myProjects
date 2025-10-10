import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("appl_1980_2014.csv", parse_dates=["Date"])
df = df.sort_values("Date")  # chronological order

period_df = df[(df["Date"] >= "2000-01-01") & (df["Date"] <= "2014-07-08")].copy()
print(period_df["Close"].describe())

# Rolling average (smooth out noise)
period_df["30_MA"] = period_df["Close"].rolling(30).mean()

# Volume spikes
volume_spikes = period_df[period_df["Volume"] > period_df["Volume"].quantile(0.95)]

plt.figure(figsize=(10,5))
plt.plot(period_df["Date"], period_df["Close"], label="Daily Close")
plt.plot(period_df["Date"], period_df["30_MA"], label="30-Day MA", linewidth=2)
plt.title("Apple Stock (2000-2014)")
plt.xlabel("Date")
plt.ylabel("Price ($)")
plt.axvline(pd.to_datetime("2007-01-09"), color="red", linestyle="--", label="iPhone Launch")
plt.rcParams.update({'font.size': 14})
plt.legend()


plt.figure(figsize=(10,5))
plt.plot(period_df["Date"], period_df["Volume"], label="Daily Volume", color="grey")

# Mark top 5 highest volume days
top_vol = period_df.nlargest(5, "Volume")
plt.scatter(top_vol["Date"], top_vol["Volume"], color="red", label="Top 5 Volume Days", zorder=5)

for _, row in top_vol.iterrows():
    plt.text(row["Date"], row["Volume"], row["Date"].strftime('%Y-%m-%d'), fontsize=10, rotation=45)

plt.title("Apple Trading Volume Spikes (2000–2014)")
plt.xlabel("Date")
plt.ylabel("Volume")
plt.legend()
plt.show()
