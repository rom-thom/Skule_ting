import numpy as np
import matplotlib.pyplot as plt

# Define the variables
k = 9e9  # constant
q = 1.602e-19  # charge
a = 2  # separation between points

# Define the function to plot
def electric_potential(y):
    return k * q * (1 / abs(y - a / 2) - 1 / abs(y + a / 2))

# Create a range of y values, avoiding singularities at y = ±a/2
y_values = np.linspace(-10, 10, 1000)
y_values = y_values[(y_values != -a / 2) & (y_values != a / 2)]

# Calculate the electric potential values
potential_values = electric_potential(y_values)

# Plot the graph
plt.figure(figsize=(10, 6))
plt.plot(y_values, potential_values, label='Electric Potential', color='blue')
plt.axhline(0, color='black', linewidth=0.8, linestyle='--')
plt.axvline(-a / 2, color='red', linestyle='--', label='Singularity at y=-a/2')
plt.axvline(a / 2, color='red', linestyle='--', label='Singularity at y=a/2')
plt.xlabel('y')
plt.ylabel('Electric Potential')
plt.title('Graph of Electric Potential')
plt.legend()
plt.grid(True)
plt.show()
