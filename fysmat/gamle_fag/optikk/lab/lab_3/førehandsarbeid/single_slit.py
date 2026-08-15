
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.widgets import Slider

def fraunhofer_approx(D, whave_len, x, y):
    return (np.sin(np.pi * D/whave_len * x/y)/(np.pi * D/whave_len * x/y))**2





# test

if __name__=="__main__":
    whave_len = 532e-9 # m
    D = 2e-6 # m
    y = 1 # m
    

    x_vals = np.linspace(-0.7, 0.7, 1000)

    plt.plot(x_vals, fraunhofer_approx(D, whave_len, x_vals, y), label="I(x)/I(0)")
    plt.legend()
    plt.title("Oppg 1")
    plt.show()

    for d in np.linspace(1e-6, 2e-5, 4):
        plt.plot(x_vals, fraunhofer_approx(d, whave_len, x_vals, y), label=f"I(x)/I(0), D = {d:.2}")
        plt.title("Oppg 2")
    plt.legend()
    plt.show()


    for l in np.linspace(200e-9, 1000e-9, 5):
        plt.plot(x_vals, fraunhofer_approx(D, l, x_vals, y), label=f"I(x)/I(0), lambda = {l:.2}")
        plt.title("Oppg 3")
    plt.legend()
    plt.show()