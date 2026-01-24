import numpy as np
from typing import Callable




"løyser ein iterasjon av g(z) = 0"
def newton_step(z: np.ndarray, Jacobian_g: Callable[[np.ndarray], np.ndarray], g: Callable[[np.ndarray], np.ndarray]):
    g_z_0 = g(z)
    J = Jacobian_g(z)

    return np.linalg.solve(J, np.negative(g_z_0))



def impl_newton(z_0: np.ndarray, Jacobian_g: Callable[[np.ndarray], np.ndarray], g: Callable[[np.ndarray], np.ndarray], tol = 1e-3, max_iter=1000):
    """g(z_end) = 0"""

    z_current = z_0

    for _ in range(max_iter):
        delta_z = newton_step(z_current, Jacobian_g, g)
        z_current += delta_z
        if np.linalg.norm(delta_z) < tol:
            return z_current

    return z_current




if __name__ == "__main__":
    z_0 = np.array([1., 99., 3.])

    def J_g(z: np.ndarray):
        return np.array([[3*(z[0]+1)**2, 0, 0], [0, 3*(z[1] + 1)**2, 0], [0, 0, 3*(z[2] + 1)**2]])
    
    def g(z:np.ndarray):
        return np.array([(z[0]+1)**3, (z[1]+1)**3, (z[2]+1)**3])


    z_end = impl_newton(z_0, J_g, g)

    print(z_end)