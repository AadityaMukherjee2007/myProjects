n = int(input("Enter Number: "))
print("\nDivisible Numbers: ")

x = 1
while x <= n:
    if n % x == 0:
        print(x)
    x += 1
