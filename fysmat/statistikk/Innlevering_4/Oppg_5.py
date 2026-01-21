# oppg 5


import numpy as np
import matplotlib.pyplot as plt
import scipy.stats as stats


x = np.array([-2.5, 0.5, 3.3, 2.6, -0.7, -4.6, 3.3, 0.8, 1.9, -0.5, 1.2, 3.8])
y = np.array([4.1, 7.2, 5.0, 7.9, 5.8, 4.9, 5.0, 5.9, 6.9, 4.8, 6.7, 3.2])



# sjekke om dei er normalfordelt
fig, axes = plt.subplots(1, 2)
stats.probplot(x, dist="norm", plot=axes[0])
axes[0].set_title("QQ-plot for mars")
stats.probplot(y, dist="norm", plot=axes[1])
axes[1].set_title("QQ-plot for Y (april)")
plt.show()



# spredningsplott for å sjå om dei harein avhengigheit
plt.scatter(x, y)
plt.title("Spreddningsplott mellom X (mars) og Y (april)")
plt.xlabel("X (mars)")
plt.ylabel("Y (april)")
plt.show()