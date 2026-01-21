import numpy as np
import matplotlib.pyplot as plt


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



def dfdx(f_0, f_1, x_0, x_1):
    return (f_1-f_0)/(x_1-x_0)

def E_field(V_field: np.ndarray, x_cor: np.ndarray, y_cor: np.ndarray):
    grad_V_field = V_field[:-1][:-1]
    for i in range(len(V_field)-2):
        for j in range(len(V_field[0])-2):
            dxV = dfdx(V_field[i][j+1], V_field[i+2][j+1], x_cor[i], x_cor[i+2])
            dyV = dfdx(V_field[i+1][j], V_field[i+1][j+2], y_cor[j], y_cor[j+2])

            grad_V_field[i][j] = -dxV - dyV
    return grad_V_field


E = E_field(V, x_cor, y_cor)

ax = plt.axes(projection="3d")
fig = plt.figure()

ax.plot_surface(xv[1:-1], yv[1:-1], E)





#plt.imshow(V, cmap="magma", interpolation="nearest")
plt.show()





