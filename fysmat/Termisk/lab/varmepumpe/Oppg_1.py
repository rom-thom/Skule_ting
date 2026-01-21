import numpy as np
import matplotlib.pyplot as plt



delta_t = 120 # Tidsforløp
c = 4.2 # varmekapasitet
m = None # masse til vatn
P = None # Kompressor effekt


T_h = np.array([]) # temp i varmt reservoar
T_c = np.array([]) # temp i kaldt reservoar


def kelvinifiser(T):
    return 273.15 + T

def del_t_inn_i_delta_t(T: np.ndarray):
    delta_t = np.zeros_like(T[1:])
    for nr, t in enumerate(T):
        if nr == 0:
            continue
        delta_t[nr-1] = t-T[nr-1]
    return delta_t

def eperimentel_virkningsgrad(delta_T_h, delta_t, P = P, c = c, m = m):
    return c*m**delta_T_h /(P * delta_t)

def carnot_virkningsgrad(T_h, T_c):
    return T_h/(T_h-T_c)



# --- Tidsakse ---
t = np.linspace(0, delta_t, 200)

# --- Simulerte temperaturar (enkelt modellert) ---
# Kaldt reservoar startar på 5 °C og aukar sakte
# Varmt reservoar startar på 60 °C og synk sakte
T_c = 5 + 10*(1 - np.exp(-t/50))      # stiger mot ~15 °C
T_h = 60 - 15*(1 - np.exp(-t/40))     # synk mot ~45 °C

# --- Plotting ---
plt.figure(figsize=(10, 6))
plt.plot(t, T_h, label='Varmt reservoar', color='red', linewidth=2)
plt.plot(t, T_c, label='Kaldt reservoar', color='blue', linewidth=2)
plt.title('Temperaturutvikling i varmt og kaldt reservoar')
plt.xlabel('Tid [s]')
plt.ylabel('Temperatur [°C]')
plt.legend()
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.show()


