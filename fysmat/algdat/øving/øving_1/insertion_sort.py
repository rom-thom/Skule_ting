def insertion_sort(A, n):
    # Skriv koden din her
    for i in range(1, n):
        val = A[i]
        j = i-1
        while j >= 0 and A[j] > val:
            A[j + 1] = A[j]
            j -= 1

        A[j + 1] = val
    return A


if __name__ == "__main__":
    A = []
    answer = sorted(A)
    student = insertion_sort(A[:], len(A))
    print(f"Answer: {answer}")
    print(f"Student: {student}")