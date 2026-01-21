import matplotlib.pyplot as plt
import numpy as np

k = 8.988e9
q = 10e-19
pos = (5, 5)

start_x, end_x = (0, 10)
start_y, end_y = (0, 10)
x_cor = np.linspace(start_x, end_x, 10)
y_cor = np.linspace(start_y, end_y, 10)

x = np.linspace(1, 1, len(x_cor))
y = np.linspace(1, 1, len(y_cor))
V, _ = np.meshgrid(x, y)


xv, yv = np.meshgrid(x_cor, y_cor)



def V_func(x, y, q):
    r = np.sqrt(x**2+y**2)
    return k*q/r

def make_V_field():
    for nr_x, i in enumerate(x_cor):
        for nr_y, j in enumerate(y_cor):
            V[nr_x][nr_y] = V_func(i-pos[0], j-pos[1], q)
    return V

V = make_V_field()



ax = plt.axes(projection="3d")
fig = plt.figure()

ax.plot_surface(xv, yv, V)





plt.imshow(V, cmap="magma", interpolation="nearest")
plt.show()


