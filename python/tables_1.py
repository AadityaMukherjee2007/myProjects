while True:
    n = int(input("Enter Number: "))

    if n == 0:
        break

    r = int(input("Enter Range: "))

    if r == 0:
        break

    i = 1
    while i <= r:
        m = i * n
        print(m)
        i = i + 1

    print()
