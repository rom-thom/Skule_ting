import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import solve_ivp

# ----- Parameter for eigenverdiane og rotasjonsvinkelen -----
# Dersom du ønskjer å bruke komplekse verdiar, skriv til dømes:
# lambda1 = 1+2j   (og då vert lambda2 automatisk satt til konjugatet 1-2j)
# I real modus kan du gi to ulike reelle verdiar.
lambda1 = 2j    # Prøv for eksempel: 1+2j 
lambda2 = -3.0  # I kompleks modus vert denne verdien overskriven
theta_deg = 45.0   # Rotasjonsvinkel (brukast berre i real modus)

# Sjekk om vi skal køyre i kompleks modus
if np.iscomplex(lambda1) or np.iscomplex(lambda2):
    # Kompleks modus: Vi antar eigenverdiane er konjugatpar
    lambda1 = complex(lambda1)
    lambda2 = np.conjugate(lambda1)
    print("Kompleks modus:")
    print("lambda1 =", lambda1, "lambda2 =", lambda2)
    # Konstruer reell representasjon for system med eigenverdier alpha ± i beta:
    alpha = lambda1.real
    beta = lambda1.imag
    A = np.array([[alpha, -beta],
                  [beta,  alpha]])
    eigenvectors_defined = False  # Reelle eigenvektorar finst ikkje i denne modusen
else:
    # Real modus: Bruk rotasjonsmatrisa for å setje eigenvektor-retningar.
    theta = np.deg2rad(theta_deg)
    P = np.array([[np.cos(theta), -np.sin(theta)],
                  [np.sin(theta),  np.cos(theta)]])
    D = np.diag([lambda1, lambda2])
    A = P @ D @ np.linalg.inv(P)
    eigenvectors_defined = True

print("Matrisa A:")
print(A)

# ----- Definer systemet -----
def system(t, x):
    return A @ x

# ----- Lag rutenett for vektorfeltet -----
x_min, x_max = -10, 10
y_min, y_max = -10, 10
X, Y = np.meshgrid(np.linspace(x_min, x_max, 20),
                   np.linspace(y_min, y_max, 20))
U = np.zeros(X.shape)
V = np.zeros(Y.shape)

# Beregn vektorfeltet: (U,V) = A*(x,y)
for i in range(X.shape[0]):
    for j in range(X.shape[1]):
        vec = np.array([X[i, j], Y[i, j]])
        dvec = A @ vec
        U[i, j] = dvec[0]
        V[i, j] = dvec[1]

plt.figure(figsize=(8,8))
plt.streamplot(X, Y, U, V, density=1.0, color='grey', linewidth=1, arrowsize=1.5)

# ----- Løys initialverdiproblemet for nokre initialbetingelsar -----
init_conditions = [[5, 0], [-5, 0], [0, 5], [0, -5], [3, 3], [-3, 3], [3, -3], [-3, -3]]
t_span = [0, 5]
t_eval = np.linspace(t_span[0], t_span[1], 200)

for ic in init_conditions:
    sol = solve_ivp(system, t_span, ic, t_eval=t_eval)
    plt.plot(sol.y[0], sol.y[1], 'b')   # løysingskurve
    plt.plot(ic[0], ic[1], 'ro')         # initialbetingelse

# ----- Tegn eigenvektor-linjene dersom eigenverdiane er reelle -----
if eigenvectors_defined:
    v1 = P[:, 0]
    v2 = P[:, 1]
    t_line = np.linspace(-10, 10, 100)
    plt.plot(t_line * v1[0], t_line * v1[1], color="green", linewidth=2, label=f'Egenvektor {lambda1}')
    plt.plot(t_line * v2[0], t_line * v2[1], color="red", linewidth=2, label=f'Egenvektor {lambda2}')

plt.xlim(x_min, x_max)
plt.ylim(y_min, y_max)
plt.xlabel('x')
plt.ylabel('y')
plt.title(f'Faseportrett: eigenverdier {lambda1}, {lambda2} med theta = {theta_deg}°')
plt.grid(True)
plt.legend()
plt.show()
