import numpy as np
import matplotlib.pyplot as plt
from kyb.gamle_fag.modsim.øving_3.oppg_1 import impl_newton
from typing import Callable


def Jacobian_g(z: np.ndarray, Jacobian_f: Callable[[np.ndarray], np.ndarray], h: float):
    I = np.identity(z.size)
    J_f = Jacobian_f(z)
    return I - h * J_f


def g(z_n:np.ndarray, x:np.ndarray, f: Callable[[float, np.ndarray], np.ndarray], delta_t: float, t:float):
    """
    This is the implisit euler, where as if z_n is the cirrect next point then this should be 0
    
    :param z_n: current zero guess
    :type z_n: np.ndarray
    :param x: startposition before moving
    :type x: np.ndarray
    :param f: x dot = f(t, x)
    :type f: Callable[[float, np.ndarray], np.ndarray]
    """
    return z_n - x -delta_t *  f(t + delta_t, z_n)


def f(t, x: np.ndarray, params: dict):
    w = params["omega"]
    return np.array([x[1], -w**2 * x[0]])



Vec = np.ndarray
Mat = np.ndarray

def implicit_euler(
    x0: Vec,
    t0: float,
    dt: float,
    steps: int,
    f: Callable[[float, Vec], Vec],
    Jf: Callable[[float, Vec], Mat],
    newton_max_iter: int = 20
) -> Vec:
    x = x0.astype(float).copy()
    t = float(t0)

    n = x.size
    I = np.eye(n)

    for _ in range(steps):
        t1 = t + dt  # t_{k+1}

        # Define G(z) and JG(z) as functions of ONLY z (closure captures x,t1,dt)
        def G(z: Vec) -> Vec:
            return z - x - dt * f(t1, z)

        def JG(z: Vec) -> Mat:
            return I - dt * Jf(t1, z)

        # Initial guess: explicit Euler
        z0 = x + dt * f(t, x)

        # Newton solve for x_{k+1}
        x = impl_newton(z0, JG, G, max_iter=newton_max_iter)

        t = t1

    return x


def implicit_euler(
    x0: Vec,
    t0: float,
    dt: float,
    steps: int,
    f: Callable[[float, Vec], Vec],
    Jf: Callable[[float, Vec], Mat],
    newton_max_iter: int = 20
) -> Vec:
    x = x0.astype(float).copy()
    t = float(t0)

    n = x.size
    I = np.eye(n)

    for _ in range(steps):
        t1 = t + dt  # t_{k+1}

        # Define G(z) and JG(z) as functions of ONLY z (closure captures x,t1,dt)
        def G(z: Vec) -> Vec:
            return z - x - dt * f(t1, z)

        def JG(z: Vec) -> Mat:
            return I - dt * Jf(t1, z)

        # Initial guess: explicit Euler
        z0 = x + dt * f(t, x)

        # Newton solve for x_{k+1}
        x = impl_newton(z0, JG, G, max_iter=newton_max_iter)

        t = t1

    return x


def Jf(t: float, x: Vec, params: dict) -> Mat:
    # df/dx = [[0, 1], [-omega^2, 0]]
    omega = params["omega"]
    return np.array([[0.0, 1.0],
                     [-(omega**2), 0.0]], dtype=float)

if __name__ == "__main__":


    params = {"omega": 2.}
    x1 = implicit_euler(
        x0=np.array([1.0, 0.0]),
        t0=0.0,
        dt=0.001,
        steps=10000,
        f=lambda t, x: f(t, x, params),
        Jf=lambda t, x: Jf(t, x, params),
        newton_max_iter=10
    )
    print(x1)
