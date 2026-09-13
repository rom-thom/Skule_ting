

# Countingsort uten stabilitet
def counting_sort(A, n):
    B = [0 for _ in range(2048)]
    for a in A:
        B[a] += 1

    C = A
    count = 0
    for val, b in enumerate(B):
        if b == 0:
            continue

        
        for _ in range(b):
            C[count] = val
            count += 1
    return C

A = [1, 3, 4, 3, 5, 7, 2, 0, 0, 1, 2, 234, 1256, 12, 234,33, 12, 100, 234]
print(counting_sort(A, len(A)))
