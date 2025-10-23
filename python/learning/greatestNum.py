# Program to find the greatest number

a = float(input("Enter 1st. Number: "))
b = float(input("Enter 2nd. number: "))
c = float(input("Enter 3rd. Number: "))

if a == b == c:
    print("All the numbers are equal!")

if a > b:
    if a > c:
        print(str(a) + " is the greatest number!")
    else:
        if c > b:
            print(str(c) + " is the greatest number!")
elif b > a:
    if b > c:
        print(str(b) + " is the greatest number!")
    else:
        if c > a:
            print(str(c) + " is the greatest number!")
elif c > a:
    if c > b:
        print(str(c) + " is the greatest number!")
    else:
        if b > a:
            print(str(b) + " is the greatest number!")
