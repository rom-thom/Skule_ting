
import numpy as np




"""Here i just implement all the expresions"""


def norm_2d(x: np.ndarray):
    """Returns the distance in the first 2 dimentions"""
    return np.sqrt(x[0]**2 + x[1]**2)

def norm_3d(x: np.ndarray):
    """Returns the distance in the first 3 dimentions"""
    return np.sqrt(x[0]**2 + x[1]**2 + x[2]**2)


def B_2d(x: np.ndarray):
    return np.array([0, 0, norm_2d(x)])


def A_2d(x: np.ndarray):
    return 1/3 * np.array([-x[1] * norm_2d(x), x[0] * norm_2d(x), 0])


def U_2d(x):
    return 1/(100 * norm_2d(x))


def nabla_U_2d(x: np.ndarray):
    return -1/100 * np.array([x[0] / norm_2d(x)**3, x[1] / norm_2d(x)**3, 0])


def B_tokamak(x: np.ndarray):
    return np.array([
        -(2*x[1] + x[0]*x[2]) / (2 * norm_2d(x)**2),
        (2*x[0] - x[1]*x[2]) / (2 * norm_2d(x)**2),
        (norm_2d(x) - 1) / (2 * norm_2d(x)),
    ])


def A_tokamak(x: np.ndarray):
    return np.array([
        0,
        1/2 * (x[0] - np.log(norm_2d(x) + x[0])),
        -1/2 * (x[2] * np.arctan(x[1] / x[0]) + np.log(norm_2d(x)**2)),
    ])


def U_tokamak(x: np.ndarray):
    return 0


def nabla_U_tokamak(x: np.ndarray):
    return np.array([0, 0, 0])


x0_2d = np.array([0.0, 1.0, 0.1])
v0_2d = np.array([0.09, 0.05, 0.20])

x0_tokamak = np.array([1.2, 0.0, 0.0])
v0_tokamak = np.array([0.0, 4.816e-4, -2.059e-3])
