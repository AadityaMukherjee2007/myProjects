a = float(input("Enter base number: "))
b = float(input("Enter power: "))

power = 1

x = 0
while x < b:
    power *= a
    x += 1

print("Power of", a, "=", power)
