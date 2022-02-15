import sqlite3 as sq
dataBase = "StudentData.db"

con = sq.connect(dataBase)
cur = con.cursor()

print("Choice:\n0 --> Exit\n1 --> Print Data\n2 --> Delete Data")
ch = int(input("\nEnter Choice: "))

if ch == 0:
  cur.close()
  con.close()
  exit()
elif ch == 1:
  for data in cur.execute("SELECT * FROM info"):
    print(data)
elif ch == 2:
  print("Choice: \n0 --> Exit\n1 --> Delete All\n2 --> Delete specific data\n")
  op = int(input("Enter Choice: "))

  if op == 0:
    cur.close()
    con.close()
    exit()
  elif op == 1:
    conf = input("Confirm? [Y/n] : ")
    conf = conf.lower()
    
    if conf == "y":
      cur.execute("DELETE FROM info")
      con.commit()
      print("Complete data deletion complete!")
    else:
      print("Complete data deletion cancelled.")
  elif op == 2:
    name = input("Enter student name: ")
    name = name.upper()
    StudentName = [name]

    cur.execute('SELECT * FROM info WHERE "Student Name" = ?', StudentName)
    if cur.fetchall():
      confirm = input("Student Name found!\nDelete data? [Y/n] : ")
      confirm = confirm.lower()

      if confirm == "y":
        cur.execute('DELETE FROM info WHERE "Student Name" = ?', StudentName)
        con.commit()
        print("Data deletion complete!")
      else:
        print("Data deletion cancelled.")
    else:
      print("Student name not found!")

cur.close()
con.close()