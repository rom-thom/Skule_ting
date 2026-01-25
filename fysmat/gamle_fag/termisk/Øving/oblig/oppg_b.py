from oppg_a import *
from matplotlib.colors import TwoSlopeNorm




def inv_kurve(T, a = a, b= b, R = R):
    T_0 = 2*a/(R*b)
    t_bar = np.sqrt(T/T_0)
    p_bar = -3*t_bar**2 + 4*t_bar - 1
   
    return p_bar*a/(b**2)
   

# Del 1 velge p og T intervallar
if __name__=="__main__":
    T_list_inv = np.arange(91, 880, 0.1)

    p_vals = inv_kurve(T_list_inv)

    plt.xlabel("T [K]")
    plt.ylabel("p [bar]")
    plt.plot(T_list_inv, p_vals)
    plt.grid(visible=True)



def alpha_V(V, T, a=a, b=b, R=R):
    return 1/V *1/(T/(V-b)-2*a*(V-b)/(R*V**3))

def C_p(n=n, R=R):
    return 7/2 * n * R


def V_skalar(p, T):
    coeffs = [p, -(p*b + R*T), a, -a*b]
    r = np.roots(coeffs)
    r = r[np.isclose(r.imag, 0.0)].real
    rp = r[r > 0]
    return np.max(rp) if rp.size else np.nan # Koffor max ¯\_(ツ)_/¯ sounds correct i guess


V = np.vectorize(V_skalar, otypes=[float])


def joule_thomson_koef(p, T):


    return V(p, T) * (T * alpha_V(V(p, T), T) -1)/C_p()


# Del 2
if __name__=="__main__":
    T_list_inv = np.linspace(91, 880, 100)
    
    p_vals = np.linspace(0.1, inv_kurve(T_list_inv).max(), 100)

    T_mesh, p_mesh = np.meshgrid(T_list_inv, p_vals)
    V_mesh = V(p_mesh, T_mesh)

    JT_k_grid = joule_thomson_koef(p_mesh, T_mesh)


    MU_bar = np.ma.masked_less_equal(JT_k_grid, 0)  # vis bare μJT > 0

    # Her skalerar vi slik at ein ser kva verdiane er betre
    valid_vals = MU_bar.compressed()  # tar ut bare dei som ikkje er maskert
    lo = np.percentile(valid_vals, 2)
    hi = np.percentile(valid_vals, 98)

    vmax = max(abs(lo), abs(hi))
    norm = TwoSlopeNorm(vmin=-vmax, vcenter=0.0, vmax=vmax) # Denne er for å skalere

    cf = plt.contourf(
        T_mesh,
        p_mesh,
        MU_bar,
        levels=200,
        cmap="coolwarm",
        extend="max",
        norm=norm,
    )

    plt.xlabel("T [K]")
    plt.ylabel("p [bar]")
    plt.ylim(0, 400)
    plt.legend()
    plt.colorbar(cf, label=r"$\mu_{JT}$ [K/bar]")
    plt.grid(True, alpha=0.3)
    plt.show()
