def display(mat):
    for row in mat:
        print(row) 
    print()

def add(a, b):
    am = len(a)
    an = len(a[0])

    bm = len(b)
    bn = len(b[0])

    if am != bm and an != bn:
        raise Exception("Matrices are of different dimensions")
    
    c = [[0] * an for _ in range(am)]
    for i in range(am):
        for j in range(an):
            c[i][j] = a[i][j] + b[i][j]
    
    return c

def subtract(a, b):
    am = len(a)
    an = len(a[0])

    bm = len(b)
    bn = len(b[0])

    if am != bm and an != bn:
        raise Exception("Matrices are of different dimensions")
    
    c = [[0] * an for _ in range(am)]
    for i in range(am):
        for j in range(an):
            c[i][j] = a[i][j] - b[i][j]
    
    return c

def multiply(a, b):
    am = len(a)
    an = len(a[0])

    bm = len(b)
    bn = len(b[0])

    if an != bm:
        raise Exception("Column of 1st matrix is not equal to Row of 2nd matrix")

    c = [[0] * bn for _ in range(am)]
    for i in range(am):
        for j in range(an):
            for k in range(bn):
                c[i][k] += a[i][j] * b[j][k]
    
    return c
        

def transpose(mat):
    m = len(mat)
    n = len(mat[0])

    trans_mat = [[0] * m for _ in range(n)]
    for i in range(n):
        for j in range(m):
            trans_mat[i][j] = mat[j][i]
    
    return trans_mat

def det(mat):
    val = 0

    

    return val