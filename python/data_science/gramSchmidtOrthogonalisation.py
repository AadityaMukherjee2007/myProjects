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
def scalarProduct(vector_1: list, vector_2: list) -> Union[float, str]:
    if len(vector_1) != len(vector_2):
        return "Vectors need to be conformable for scalar product"

    val = 0
    for i in range(len(vector_1)):
        val += vector_1[i] * vector_2[i]
    
    return val


# function to check whether the set of vectors are orthogonal or not
def check_orthogonality_of_set(set_of_vectors: list) -> bool:
    for i in range(len(set_of_vectors)):
        for j in range(i + 1, len(set_of_vectors)):
            if (scalarProduct(set_of_vectors[i], set_of_vectors[j]) != 0):
                return False
    return True


# function to implement Gram Schmidt Orthogonalisation to Orthonormalise a set of orthogonal vectors
def gram_schmidt(set_of_vectors: list) -> Union[list, str]:
    output_set = []
    u1 = set_of_vectors[0]
    output_set.append(u1)

    for i in range (1, len(set_of_vectors)):
        ...
    


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
    
    for i in range(n):
        print(f"Vector {i}: ", end="")
        vector = []
        for _ in range(dimension):
            vector.append(float(input()))
        vectors.append(vector)
        print()

    print(vectors)


def main():
    # setInput()

    # vector_1 = [1, 2, 4]
    # vector_2 = [2, -1]
    # print(scalarProduct(vector_1, vector_2))

#     vectors = [
#     [1, 2, -1],
#     [2, -1, 0],
#     [1, 1, 2]
# ]   
#     print(check_orthogonality_of_set(vectors))

    ...


if __name__ == "__main__":
    main()