import numpy as np
from itertools import combinations


def C_candid(n):
    C_candidates = []
    for k in range(n + 1):
        for idx in combinations(range(n), k):
            C = np.zeros((n, n), dtype=int)
            for i in idx:
                C[i, i] = 1
            C_candidates.append(C)
    return C_candidates


def observability_matrix(A, C):
    A = np.asarray(A)
    C = np.asarray(C)

    n = A.shape[0]
    M = [C.copy()]

    for _ in range(1, n):
        M.append(C @ np.linalg.matrix_power(A, _))

    return np.vstack(M)


n = 5
K_3 = 5
A = np.array([[1, 0, 0, 0, 0], [0, 0, 0, 0, 0], [0, 0, 0, 1, 0], [0, 0, 0, 0, 0], [K_3, 0, 0, 0, 0]])
C_candidates = C_candid(n)
for C in C_candidates:

    if np.linalg.matrix_rank(observability_matrix(A, C)) == n:
        print(C)