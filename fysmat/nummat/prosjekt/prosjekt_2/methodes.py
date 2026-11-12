from collections.abc import Callable

import numpy as np
from numpy.typing import ArrayLike
from fysmat.nummat.prosjekt.prosjekt_2.expresions import *



def rk4(x_n: np.ndarray, v_n: np.ndarray, f: Callable, h: float):
    """Her er det eigentleg bare å implementere i følge bucher tabellen og sidan den er eksplisit er det relativt enkelt:
    0   | 0        0       0     0
    1/2 | 1/2      0       0     0
    1/2 | 0        1/2     0     0
    1   | 0        0       1     0
    --------------------------------
        | 1/6      1/3     1/3   1/6   

    (c kolonna blir ikkje bruk  sidan det ikkje er eksplisit avhengigheit av tid)

    Posisjon og fart kan lagrast separat, men må oppdaterast 
    saman i kvart RK4-delsteg, sidan likningane er kopla.

    (Ein kunne eventuelt brukt ein tilstand y = [x, v]^T, 
    men da måtte eg splitta det opp før eg tok det inn i utrykka)
    """

    k1_v = h * f(x_n, v_n)
    k1_x = h * v_n

    k2_v = h * f(x_n + 1/2 * k1_x, v_n + 1/2 * k1_v)
    k2_x = h * (v_n + 1/2 * k1_v)

    k3_v = h * f(x_n + 1/2 * k2_x, v_n + 1/2 * k2_v)
    k3_x = h * (v_n + 1/2 * k2_v)

    k4_v = h * f(x_n + k3_x, v_n + k3_v)
    k4_x = h * (v_n + k3_v)

    v_n_plus_1 = v_n + (1/6 * (k1_v + k4_v) + 1/3 * (k2_v + k3_v))
    x_n_plus_1 = x_n + (1/6 * (k1_x + k4_x) + 1/3 * (k2_x + k3_x))

    return x_n_plus_1, v_n_plus_1




def boris(x_n: np.ndarray, v_n_min_half: np.ndarray, h: float, B: Callable, nabla_U: Callable):
    """
    Here i honestly dont understand why it works, and i just folowed the formula
    returns: x_n+1 og v_n+1/2
    """

    t = h/2 * B(x_n)
    s = 2*t/(1+np.dot(t, t))
    v_min = v_n_min_half - h/2 * nabla_U(x_n)

    v_mark = v_min + np.cross(v_min, t)


    v_plus = v_min + np.cross(v_mark, s)
    v_n_plus_half = v_plus - h/2 * nabla_U(x_n)
    x_next = x_n + h * v_n_plus_half

    return x_next, v_n_plus_half


def multistep(x_init: np.ndarray, h: float, A: Callable, A_jacobi: Callable, nabla_U: Callable):
    """Her treng ein dei forje 8 x verdiane for å finne den neste
    """
    if len(x_init) != 8:
        raise ValueError("x_init must be accactly the 8 values before the new point")

    a1, a2, a3 = [-0.7, 0.1, 0.9]
    beta = np.array([
        1/3 * (20*a1*a2*a3 - 4*(a1*a2 + a1*a3 + a2*a3) - 28*(a1 + a2 + a3) - 52),
        1/3 * (2*a1*a2*a3 + 14*(a1*a2 + a1*a3 + a2*a3) + 26*(a1 + a2 + a3)+ 38),])

    alpha = np.array([1, -7/5, 9/25, 22/125, -34/125, 22/125, 9/25, -7/5, 1])


    def delta(y: ArrayLike):
        # Here y is a 4 long array of values [y_(j-2), y_(j-1), y_(j+1), y_(j+2)]
        return 1/12 * (y[0] - 8 * y[1] + 8 * y[2] - y[3])
    
    def x_surrounding(j):
        return np.array([x_init[4 + j - 2], x_init[4 + j - 1], x_init[4 + j + 1], x_init[4 + j + 2]])
    def v(j):
        return delta(x_surrounding(j))/h
    def A_delta(j):
        return delta(np.array([A(x_j) for x_j in x_surrounding(j)]))/h
    def F(j):
        return A_jacobi(x_init[4 + j]).T @ v(j) - A_delta(j) - nabla_U(x_init[4 + j])
    
    # Dei indeksane va eit herk
    right_side = h**2 * (beta[1] * (F(-1) + F(1)) + beta[0] * F(0))

    x_next = right_side - sum([alpha[j] * x_init[j] for j in range(8)])

    return x_next

