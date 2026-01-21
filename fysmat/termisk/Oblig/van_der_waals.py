import matplotlib.pyplot as plt
import numpy as np


# Konstantar:
n = 1 # [mol]
R = 8.314462618 # [J/(mol * K)]


def p_van_der_waals(T, V, a, b, n=n):
    return n*R*T/(V-n*b) - a*n**2/V**2
