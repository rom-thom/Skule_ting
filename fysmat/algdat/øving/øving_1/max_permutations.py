def max_permutations(M):
    # Skriv koden din her
    """loops = []
    for nr, favorit in enumerate(M):
        if favorit == nr:
            continue

        if nr in loops:
            continue
        
        potential_loop = [nr]
        fav = favorit
        while fav not in potential_loop:
            potential_loop.append(fav)
            fav = M[fav]
        if fav == potential_loop[0]:
            loops.extend(potential_loop)
        elif fav in potential_loop:
            if len(potential_loop[potential_loop.index(fav):]) > 1:
                loops.extend(potential_loop[potential_loop.index(fav):])
    return set(loops)"""
    pass




if __name__ == "__main__":
    M = [
                56, 65, 31, 39, 46, 49, 55, 16, 55, 55, 49, 52, 10, 41, 47, 54,
                3, 15, 20, 3, 42, 65, 10, 62, 17, 42, 55, 27, 9, 37, 69, 1, 50,
                24, 41, 16, 31, 69, 20, 67, 65, 39, 64, 60, 49, 52, 14, 67, 27,
                17, 53, 60, 18, 69, 49, 0, 6, 63, 68, 2, 69, 52, 24, 20, 36, 34,
                1, 57, 45, 32
            ]
    answer = [frozenset([0]), frozenset([1])]
    student = max_permutations(M)
    print(f"Answer: {answer}")
    print(f"Student: {student}")