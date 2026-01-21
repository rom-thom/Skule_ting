
import matplotlib.pyplot as plt
import numpy as np


d = 0
m = 1
k = 1



def y_1_dot(y_1_, y_2_, t):
    return y_2_

def y_2_dot(y_1_, y_2_, t):
    return -d/m * y_2_-k/m * y_1_
    

def y_dot(t, y, params):
    y_1_, y_2_ = y # Extract state variables
    dydt_1 = y_1_dot(y_1_, y_2_, t) # Your system of 1st order ODEs
    dydt_2 = y_2_dot(y_1_, y_2_, t)
    return [dydt_1, dydt_2] # Must have same shape as y



def next_y(y, delta_y):
    y_1, y_2 = y
    y_dot_ = y_dot(delta_y, y, "hei")
    return delta_y * y_dot_[0] + y_1, delta_y * y_dot_[1] + y_2




if __name__ == "__main__":
    y_1_start = 5
    y_2_start = 5
    delta_y = 0.01

    y_1 = [y_1_start]
    y_2 = [y_2_start]

    for i in range(1000):
        y_dot_ = y_dot(delta_y, (y_1[i], y_2[i]), "hei")
        y_1_temp, y_2_temp = next_y((y_1[i], y_2[i]), delta_y)
        y_1.append(y_1_temp)
        y_2.append(y_2_temp)

    plt.plot(y_1)
    plt.show()
