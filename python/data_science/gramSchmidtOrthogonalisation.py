import sys
from typing import Union

vectors = []

# function to find the magnitude of the vector
def magnitude(vector: list) -> float:
    squared_sum = 0.0

    for i in vector:
        squared_sum += i * i
    return squared_sum ** (1 / 2)   


# function to find out scalar product of two vectors
def scalarProduct(vector_1: list, vector_2: list) -> float:
    val = 0
    for i in range(len(vector_1)):
        val += vector_1[i] * vector_2[i]
    
    return val

# function to add two vectors
def addVectors(vector1: list, vector2: list) -> list:
    for i in range(len(vector1)):
        vector1[i] += vector2[i]
    return vector1


# function to subtract two vectors
def subtractVectors(vector1: list, vector2: list) -> list:
    for i in range(len(vector1)):
        vector1[i] -= vector2[i]
    return vector1


# function to multiply a scalar to a vector
def multiplyScalar(vector: list, scalar: float) -> list:
    for i in range(len(vector)):
        vector[i] *= scalar
    return vector


# function to check whether the set of vectors are orthogonal or not
def check_orthogonality_of_set(set_of_vectors: list) -> bool:
    for i in range(len(set_of_vectors)):
        for j in range(i + 1, len(set_of_vectors)):
            if (scalarProduct(set_of_vectors[i], set_of_vectors[j]) != 0):
                return False
    return True


# function to implement Gram Schmidt Orthogonalisation to Orthonormalise a set of orthogonal vectors
def gram_schmidt(v: list) -> Union[list, str]:

    # if not check_orthogonality_of_set(v):
    #     return "set of vectors are not mutually orthogonal"

    u = []
    u.append(v[0])

    for i in range(1, len(v)):
        sum = [0 for _ in range(len(v[0]))]
        for j in range(i):
            sum = addVectors(sum, multiplyScalar(u[j][:], (scalarProduct(v[i], u[j]) / magnitude(u[j]) ** 2)))
        u.append(subtractVectors(v[i][:], sum))

    for i in range(len(u)):
        u[i] = multiplyScalar(u[i], 1 / magnitude(u[i]))
    return u
    


# function to get the set of vectors
def setInput() -> None:

    # dimension is the variable to store the dimension of the vector
    dimension = int(input("Vector Dimension: "))

    if dimension < 0:
        print("Dimension cannot be -ve.")
        sys.exit()
    
    # n is the cardinality of the set of vectors
    n = int(input("Number of Vectors: "))

    if n < 0:
        print("Cardinality of set cannot be -ve.")
        sys.exit()
    
    print("\nEnter set of vectors: ")
    for i in range(n):
        vector = []
        for _ in range(dimension):
            vector.append(float(input(f"Vector {i} [{_}]: ")))
        vectors.append(vector)
        print()

    # print(vectors)


def main():
    # setInput()
    # print(gram_schmidt(vectors))

    test_vectors = [
        [3, 0, 0],
        [0, -2, 0],
        [0, 0, 5]
    ]

    # print(magnitude([3, 0, 0]), magnitude([0, -2, 0]))
    # print(scalarProduct([3, 0, 0], [0, -2, 0]))

    # test_vectors = [
    #     [1, 1, 0],
    #     [1, 0, 1],
    #     [0, 1, 1]
    # ]

    print(gram_schmidt(test_vectors)) 

    # v1 = [1, 2, 3]
    # v2 = [3, 2, 1]
    # print(subtractVectors(v1, v2))



if __name__ == "__main__":
    main()