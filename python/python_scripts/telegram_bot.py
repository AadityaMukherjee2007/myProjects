import asyncio, time
from datetime import datetime
from telegram import Bot

tk = [""]
c_id = [""]

async def main():
    while True:
        hr = int(datetime.now().strftime("%H"))
        if hr >= 23 or hr <= 5:
                continue

        for i in range(len(tk)):
                bot = Bot(token=tk[i])
                await bot.send_message(chat_id=c_id[i], text="Drink Water")
        time.sleep(1)

asyncio.run(main())



