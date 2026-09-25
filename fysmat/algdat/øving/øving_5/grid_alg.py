
import numpy as np

def f(i, j):
    r = np.ones((i,j))
    for x_ in range(i-1):
        x = x_ + 1
        for y_ in range(j-1):
            y = y_ + 1
            r[x, y] = r[x-1, y] + r[x, y-1]
    return r[i-1, j-1]