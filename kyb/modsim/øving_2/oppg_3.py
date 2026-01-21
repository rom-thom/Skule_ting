import numpy as np
import matplotlib.pyplot as plt
# a

def y_dot(y: np.ndarray, t, params: dict):
    y_1, y_2 = y
    f = params["f"]
    omega = params["omega"]
    return np.array([y_2, -2 * f * omega * y_2 + omega**2 * np.sin(y_1)])


def next_y_heun(y:np.ndarray, t: float, delta_t: float, params: dict):
    k_1 = y_dot(y, t, params)
    k_2 = y_dot(y + k_1 * delta_t, t + delta_t, params)

    return y + delta_t * (k_1 + k_2)/2

def next_y_midpoint(y:np.ndarray, t: float, delta_t: float, params: dict):
    k_1 = y_dot(y, t, params)
    k_2 = y_dot(y + k_1 * delta_t/2, t + delta_t/2, params)

    return y + delta_t * (k_1 + k_2)/2




def implement_method(y_0: np.ndarray, t_0:float, delta_t:float, iter_count:int, params:dict, next_y):
    y = [y_0]
    for i in range(iter_count):
        y_next = next_y(y[-1], t_0 + delta_t * i, delta_t, params)
        y.append(y_next)
    return np.array(y)



if __name__ == "__main__":
    params = {"f": 0.02, "omega": 10}
    y_0 = np.array([0, 1])
    t_0 = 0
    delta_t = 0.01
    y = implement_method(y_0, t_0, delta_t, 500, params, next_y_heun)
    y_mid = implement_method(y_0, t_0, delta_t, 500, params, next_y_midpoint)
    
    plt.plot(y[:, 0], label='y_1')
    plt.plot(y[:, 1], label='y_2')


    plt.plot(y_mid[:, 0], label='y_1_mid')
    plt.plot(y_mid[:, 1], label='y_2_mid')
    plt.legend()
    plt.show()