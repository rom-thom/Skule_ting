

import numpy as np
import matplotlib.pyplot as plt

# Erstatt desse med dine avlesingar frå log p–h-diagrammet (Fig. 2.9):
T_C = np.array([-60, -40, -20, 0, 20, 40, 60, 80, 100], dtype=float)  # °C
p_kPa = np.array([0.15, 0.55, 1.5,3, 5.2, 9, 16, 24, 35], dtype=float)  # 

# Plott log10(p) mot T (enkeltlogaritmisk skala)
plt.figure(figsize=(7,5))
plt.plot(T_C, np.log10(p_kPa), marker='o')
plt.xlabel('Temperatur T [°C]')
plt.ylabel('log10 p_s [kPa]')
plt.title('Damptrykkurve for R134a (frå log p–h-diagram)')
plt.grid(True, linestyle='--', alpha=0.6)
plt.tight_layout()
plt.show()