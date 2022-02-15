txt = "Everyone should try to be positive..."

print(txt + "\n")
print(txt[3])

print("Everyone" in txt)
print("else" in txt)
print("else" not in txt)

if "Everyone" in txt:
    print("'Everyone' is present in txt")

if "else" not in txt:
    print("'else' is not present in txt")


txt2 = "Hello, World!"
print("\n" + txt2  +"\n")

print(txt2[2:5])
print(txt2[:5])
print(txt2[2:])
print(txt2[-5:-2])


txt3 = " Life's Good "
print("\n" + txt3 + "\n")

print(txt3.lower())
print(txt3.upper())
print(txt3.strip()) # removes white spaces
print(txt3.replace("o", "i"))

t = txt3.strip()
t1 = t.split(" ")
print(t1)


age = 14
txt4 = "\nMy name is Alex, and I am {} yrs old."
print(txt4.format(age))

quantity = 3
itemno = 567
price = 1560
myorder = "I want {} pieces of item {} for {} rupees."
print(myorder.format(quantity, itemno, price))
myorder = "I want to pay {2} for {0} pieces of item {1}"
print(myorder.format(quantity, itemno, price))


txt5 = "We are the so-called \"Vikings\" from the north."
print(txt5)

txt6 = "Apple"
print("\n\n")
for x in txt6:
    print(x)
