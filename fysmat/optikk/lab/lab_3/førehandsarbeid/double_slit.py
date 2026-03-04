

import numpy as np
import matplotlib.pyplot as plt


def double_fraunhofer_approx(D, whave_len, x, y, l, N):
    return (np.sin(np.pi * D/whave_len * x/y)/(np.pi * D/whave_len * x/y))**2 * (np.cos(np.pi * l/(whave_len * y) * x))**2





if __name__ == "__main__":
    whave_len = 532e-9 # m
    D = 2e-6 # m
    y = 1 # m
    l = 4e-6 # m
    N = 3


    x_vals = np.linspace(-0.7, 0.7, 1000)

    plt.plot(x_vals, double_fraunhofer_approx(D, whave_len, x_vals, y, l, N), label="I(x)/I(0)")
    plt.legend()
    plt.title("Oppg 1 (double slit)")
    plt.show()

    for l_ in np.linspace(1e-6, 10e-6, 3):
        plt.plot(x_vals, double_fraunhofer_approx(D, whave_len, x_vals, y, l_, N), label=f"I(x)/I(0), l={l_:.2}")
    plt.legend()
    plt.title("Oppg 2 (double slit)")
    plt.show()
