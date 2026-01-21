import numpy as np
import matplotlib.pyplot as plt


R = 8.314
M = 43.34
g = 3.71



def T(z):
    return 234-2.25*z + 14*np.exp(-2*z)



def integral(f, x_1, x_2, n):
    h = (x_2 - x_1)/n
    s = f(x_1) + f(x_2)
    def x(i):
        return x_1 + i * h
    for i in range(n-1):
        if i % 2 == 0:
            s += 4*f(x(i+1))
        else:
            s += 2*f(x(i+1))

    return s*h/3

def div_H(z):
    return 1/(R*T(z)/(g*M))


def p(z, p_0):
    return p_0 * np.exp(-integral(div_H, 0, z, 20))

x = np.linspace(0, 10)

y = p(x, 26)

plt.plot(x, y)

plt.show()
