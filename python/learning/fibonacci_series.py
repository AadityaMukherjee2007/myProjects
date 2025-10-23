n = int(input("Enter Range: "))

x, c, a, b = 1, 0, 0, 1
for i in range(x, (n + 1)):
    print(a)
    c = a + b
    a = b
    b = c
    
