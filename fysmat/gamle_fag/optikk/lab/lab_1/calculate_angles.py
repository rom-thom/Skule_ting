import matplotlib.pyplot as plt
import numpy as np
# n_i = infalls_refraksjonskoefisient
# n_t = utfalls_refraksjonskoefisient

def utfallsvinkel(infallsvinkel, n_i, n_t):
    if n_i/n_t * np.sin(infallsvinkel) > 1:
        return np.pi/2
    return np.asin(n_i/n_t * np.sin(infallsvinkel))



# n_i = 

def r_TE(n_i, n_t, theta_i, theta_t):
    return (n_i* np.cos(theta_i) - n_t * np.cos(theta_t))/(n_i * np.cos(theta_i) + n_t * np.cos(theta_t))

def r_TM(n_i, n_t, theta_i, theta_t):
    return (n_t* np.cos(theta_i) - n_i * np.cos(theta_t))/(n_t * np.cos(theta_i) + n_i * np.cos(theta_t))





if __name__ == "__main__":
    n_air = 1
    n_water = 1.334

    r_TE_list_vl = []
    r_TE_list_lv = []
    r_TM_list_vl = []
    r_TM_list_lv = []
    theta_i_list = np.linspace(0, np.pi/2-0.001, 100)
    for theta_i in theta_i_list:
        theta_t_lv = utfallsvinkel(theta_i, n_air, n_water) # frå luft til vatn
        r_TM_list_lv.append(r_TM(n_air, n_water, theta_i, theta_t_lv))
        theta_t_vl = utfallsvinkel(theta_i, n_water, n_air) # frå vatn til luft
        r_TM_list_vl.append(r_TM(n_water, n_air, theta_i, theta_t_vl))

        theta_t_lv = utfallsvinkel(theta_i, n_air, n_water) # frå luft til vatn
        r_TE_list_lv.append(r_TE(n_air, n_water, theta_i, theta_t_lv))
        theta_t_vl = utfallsvinkel(theta_i, n_water, n_air) # frå vatn til luft
        r_TE_list_vl.append(r_TE(n_water, n_air, theta_i, theta_t_vl))



    plt.plot(theta_i_list, r_TM_list_vl, label="r_TM frå luft til vatn")
    plt.plot(theta_i_list, r_TM_list_lv, label="r_TM frå vatn til luft")

    plt.plot(theta_i_list, r_TE_list_vl, label="r_TE frå luft til vatn")
    plt.plot(theta_i_list, r_TE_list_lv, label="r_TE frå vatn til luft")
    
    theta_b_vl = np.atan(n_water/n_air)
    theta_b_lv = np.atan(n_air/n_water)
    plt.axvline(theta_b_lv, linestyle="--", label=f"Brewster angle (luft -> vatn) ≈ {theta_b_lv:.3f} radianar")
    plt.axvline(theta_b_vl, linestyle="--", label=f"Brewster angle (vatn -> luft) ≈ {theta_b_vl:.3f} radianar")
    plt.xlabel("vinklar frå 0 til pi/2")
    plt.legend()
    plt.show()
    
