x = lambda a: a + 10
print(x(5))


def myFunc(n):
    return lambda b: b * 2


myDoubler = myFunc(2)
print(myDoubler(14))
