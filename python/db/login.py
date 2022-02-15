import sqlite3 as sq
import getpass as gp

con = sq.connect("loginData.db")
cur = con.cursor()

cur.execute("CREATE TABLE IF NOT EXISTS usrPasswd (Username TEXT, Password TEXT)")

LoginData = [()]
username = ""
password = ""

print("Software Z: ")

while True:
    ch = int(input("\nChoice: \n0 --> Exit\n1 --> Login\n2 --> Register\n\nEnter Choice: "))

    if ch == 0:
        break
    elif ch == 1:
        username = str(input("Username: "))
        user = [username]
        cur.execute("Select password FROM usrPasswd WHERE username = ?", user)
        if not cur.fetchall():
            print("Username not found. \nPlease register.")
            continue

        password = gp.getpass("Password: ")

        cur.execute("SELECT * FROM usrPasswd WHERE username = ? AND password = ?", (username, password))
        if cur.fetchall():
            print("Login Successful!")
            break
        else:
            print("Login Unsuccessful!\nEither username or password is wrong.")
            continue

    elif ch == 2:
        username = str(input("Username: "))
        user = [username]
        cur.execute("SELECT password FROM usrPasswd WHERE username = ?", user)
        if cur.fetchall():
            print("Username already taken. Please choose another one.\nRegistration Unsuccessful!")
            continue

        while True:
            passkey = gp.getpass("Password: ")
            if passkey == "0":
                break
            password = gp.getpass("Rewrite Password: ")
            if passkey != password:
                print("Passwords do not match!\n\nRetry or enter '0' to return to main menu.")
                continue
            else:
                break

        if passkey == "0":
            break

        LoginData = [(username, password)]

        reg = input("Register? [Y/n] : ")
        reg = reg.lower()

        if reg == "y":
            cur.executemany('INSERT INTO "usrPasswd" VALUES (?, ?)', LoginData)
            con.commit()
            print("Registration Successful!")
        else:
            print("Registration Unsuccessful!")

cur.close()
con.close()
