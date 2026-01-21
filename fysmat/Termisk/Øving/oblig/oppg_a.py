import numpy as np
import matplotlib.pyplot as plt

#konstantar
a = 1.39          # L^2·bar/mol^2
b = 0.039         # L/mol
R = 0.08314       # L·bar/(mol·K)
n = 1             # mol

def p_van_der_waals(T, V, a, b, n=1):
    return n*R*T/(V - n*b) - a*n**2 / V**2

T_list = np.arange(86, 286 + 40, 40)  # 86 K, 286 K, delta T = 40 K
Vm = np.linspace(0.06, 0.60, 800)     # [L/mol]


if __name__=="__main__":
        
    plt.figure(figsize=(8,5))
    for Ti in T_list:
        p = p_van_der_waals(Ti, Vm*n, a, b, n)
        plt.plot(Vm, p, lw=1.6, label=f"T = {Ti} K")


    Ti = 286
    p_ideal = R*Ti / Vm
    plt.plot(Vm, p_ideal, ls="--", label="Ideell gass (286 K)")

    plt.xscale("log")
    plt.xlabel("V [L/mol] (log-skala)")
    plt.ylabel("p [bar]")
    plt.title("van der Waals-isotermer for N₂ (med ideell gass ved 286 K)")
    plt.legend()
    plt.grid(True, which="both", ls="--")
    plt.tight_layout()
    plt.show()
