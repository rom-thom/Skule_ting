
import numpy as np
import matplotlib.pyplot as plt


def diffraction_fraunhofer_approx(D, whave_len, x, y, l, N):
    return (np.sin(np.pi * D/whave_len * x/y)/(np.pi * D/whave_len * x/y))**2 * (np.sin(N * np.pi * l/whave_len * x/y)/(N*np.sin(np.pi * l * x/(whave_len * y))))**2






if __name__ == "__main__":
    whave_len = 532e-9 # m
    D = 2e-6 # m
    y = 1 # m
    l = 4e-6 # m
    N = 3


    x_vals = np.linspace(-0.7, 0.7, 1000)

    plt.plot(x_vals, diffraction_fraunhofer_approx(D, whave_len, x_vals, y, l, N), label="I(x)/I(0)")
    plt.legend()
    plt.title("Oppg 1 (diffraction grating)")
    plt.show()

    for n in np.linspace(1, 4, 4):
        plt.plot(x_vals, diffraction_fraunhofer_approx(D, whave_len, x_vals, y, l, n), label=f"I(x)/I(0), N={n}")
    plt.legend()
    plt.title("Oppg 2 (diffraction grating)")
    plt.show()
