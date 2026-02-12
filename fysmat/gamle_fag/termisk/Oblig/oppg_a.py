from van_der_waals import *



# konstantar
a = 1.39 # [L**2*bar/mol**2]
b = 0.039 # [L/mol]
T = np.arange(86, 286 + 40, 40) # [K]
v = np.linspace(0.06, 0.6) # [L/mol]




if __name__ == "__main__":
    plt.figure(figsize=(8, 5))

    for T_i in T:
        p = p_van_der_waals(T_i, v * n, a, b, n)
        plt.plot(v * n, p, linewidth=1.6, label=f"T = {T_i} K")

    # make x-axis logarithmic
    plt.xscale("log")

    # labels and title
    plt.xlabel("V [L]  (log scale)")
    plt.ylabel("p [bar]")
    plt.title("van der Waals isothermar for N_2 (logaritmisk V-akse)")
    plt.legend(title="Isothermar", ncol=2, fontsize=9, title_fontsize=10)
    plt.grid(True, which="both", linestyle="--", alpha=0.6)
    plt.tight_layout()
    plt.show()