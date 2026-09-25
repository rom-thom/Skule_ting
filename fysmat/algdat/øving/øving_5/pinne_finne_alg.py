import numpy as np
from timeit import repeat

def pinne_finne(p, l):
    memo = {0: 0}

    def finn_pinne(n):
        if n in memo:
            return memo[n]

        p_temp = 0
        p_max = 0
        for i in range(n):
            p_temp = p[i] + pinne_finne(p, n -(i+1))

            max_idx = i
            p_max = max(p_temp, p_max)

        memo[n] = p_max
        return p_max
    return finn_pinne(l)

def pinne_finne_treig(p, l):

    if n ==0:
        return 0

    p_temp = 0
    p_max = 0
    for i in range(n):
        p_temp = p[i] + pinne_finne(p, n -(i+1))

        max_idx = i
        p_max = max(p_temp, p_max)

    return p_max




if __name__ == "__main__":
    print(f"{'n':>3} {'Utan memo (ms)':>16} {'Med memo (ms)':>16} {'Fartsauke':>12}")

    for n in [10, 15, 20, 30]:
        p = [3 * i + i % 4 for i in range(1, n + 1)]

        # Sjekk at begge gir same svar.
        assert pinne_finne_treig(p, n) == pinne_finne(p, n)

        # Beste av tre målingar. Memo blir oppretta på nytt kvart kall.
        tid_utan = min(repeat(
            lambda: pinne_finne_treig(p, n), number=1, repeat=2
        ))
        tid_med = min(repeat(
            lambda: pinne_finne(p, n), number=100, repeat=2
        )) / 100

        print(
            f"{n:3} {tid_utan * 1000:16.4f} "
            f"{tid_med * 1000:16.4f} {tid_utan / tid_med:11.1f}x"
        )