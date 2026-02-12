import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm, probplot

# Gitte verdiar
mu_x, sigma_x = 150, 5
mu_y, sigma_y = 200, 7
mu_t, sigma_t = 0.9, 0.05
n = 10000


X = np.random.normal(mu_x, sigma_x, n)
Y = np.random.normal(mu_y, sigma_y, n)
T = np.random.normal(mu_t, sigma_t, n)


A = 0.5 * X * Y * np.sin(T)

mu_a = np.mean(A)
sigma_a = np.std(A, ddof=1)

print("Tilnærma verdiar:")
print("mu_a =", mu_a)
print("sigma_a =", sigma_a)


plt.hist(A, bins=40, density=True)
x = np.linspace(min(A), max(A), 400)
plt.plot(x, norm.pdf(x, mu_a, sigma_a)) 
plt.xlabel("A")
plt.ylabel("Tettheit")
plt.show()

plt.show()
