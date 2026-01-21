import numpy as np
import matplotlib.pyplot as plt


# a

def X(my, sigma, n=1):
    return my + np.random.normal(size=n)*sigma


def Y(my, sigma, a, b, n):
    return X(my, sigma, n) * a + b

#test:

def test_y():
    y = Y(1, 2, 2, 0.5, 100_000)
    plt.hist(y, bins=100, density=True)

def plot_normal(my, sigma, a, b):
    ny_my = a*my + b
    ny_sigma = a*sigma
    x = np.linspace(-20, 20)
    Z = 1/(np.sqrt(np.pi * 2) * ny_sigma) * np.exp(-1/2 * ((x-ny_my)/ny_sigma)**2)


    plt.plot(x, Z)

if __name__ == "__main__":
    test_y()
    plot_normal(1, 2, 2, 0.5)

    plt.show()
