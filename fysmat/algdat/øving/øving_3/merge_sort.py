import math


def merge(A, p, q, r):
    L = A[p:q+1]
    R = A[q+1:r+1]

    i_L = 0
    i_R = 0
    for i in range(r-p+1):
        j = i + p
        if i_L >= len(L) and i_R >= len(R):
            return
        if i_L >= len(L):
            A[j] = R[i_R]
            i_R += 1
            continue
        if i_R >= len(R):
            A[j] = L[i_L]
            i_L += 1
            continue
        if L[i_L] > R[i_R]:
            A[j] = R[i_R]
            i_R += 1
        else:
            A[j] = L[i_L]
            i_L += 1
        


def merge_sort(A, p, r):

    if abs(r-p) < 2:
        merge(A, p, p, r)
        return

    i = math.floor((r+p)/2)

    merge_sort(A, p, i)
    merge_sort(A, i+1, r)

    merge(A, p, i, r)







if __name__ == "__main__":
    A=[7, 8, 6, 6, 5, 4, 5, 5, 4, 10, 7]
    print(A)
    merge(A, 4, 5, 9)
    print(A)