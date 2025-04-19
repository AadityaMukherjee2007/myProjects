from matrices import add, subtract, display, transpose, multiply

def main():
    a = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    b = [[9, 5, 7], [6, 11, 13], [2, 1, 9]]
    c = [[13, 2], [27, 5], [1, 7]]
    d = [[2, 3], [4, 5]]
    e = [[4, 2], [3, 2]]

    display(a)
    display(b)

    display(add(a, b))
    display(subtract(b, a))

    display(transpose(c))

    display(multiply(d, e))
    display(multiply(b, c))


if __name__ == "__main__":
    main()