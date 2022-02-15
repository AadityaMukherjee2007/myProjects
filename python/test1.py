a = int(input("Enter Number Limit: "))
c = 0
b = 1  # loop variable
while b < a:
    if a % b == 0:
        c += 1
    b += 1
if c > 1:
    print("The number is non-prime")
else:
    print("The number is prime")

