import sympy as sp
from IPython.display import display_latex



# Handout

mass_1, mass_2, L, g = sp.symbols("m_1 m_2 L g")
force = sp.Matrix(sp.symbols("u1 u2 u3"))

point_mass_1 = sp.Matrix(sp.symbols("{p_1}_1 {p_1}_2 {p_1}_3"))
d_point_mass_1 = sp.Matrix(sp.symbols("\\dot{p_1}_1 \\dot{p_1}_2 \\dot{p_1}_3"))
dd_point_mass_1 = sp.Matrix(sp.symbols("\\ddot{p_1}_1 \\ddot{p_1}_2 \\ddot{p_1}_3"))

angles = sp.Matrix(sp.symbols("{\\theta} {\\phi}"))
d_angles = sp.Matrix(sp.symbols("\\dot{\\theta} \\dot{\\phi}"))
dd_angles = sp.Matrix(sp.symbols("\\ddot{\\theta} \\ddot{\\phi}"))

q = sp.Matrix.vstack(point_mass_1, angles)
d_q = sp.Matrix.vstack(d_point_mass_1, d_angles)
dd_q = sp.Matrix.vstack(dd_point_mass_1, dd_angles)




# Oppgåve:

theta = angles[0]
phi = angles[1]

point_mass_2: sp.Matrix = point_mass_1 + L * sp.Matrix([sp.cos(theta) * sp.sin(phi)
                                            , sp.sin(theta) * sp.sin(phi)
                                            , sp.cos(phi)])

d_point_mass_2: sp.Matrix = point_mass_2.jacobian(q) @ d_q


Q = point_mass_1.jacobian(q).transpose() @ force # Generaliserte krefter


T = sp.Rational(1, 2) * (mass_1 * d_point_mass_1.transpose() @ d_point_mass_1 + mass_2 * d_point_mass_2.transpose() @ d_point_mass_2)

T = sp.simplify(T[0])


V = sp.simplify(g * (mass_1 * point_mass_1[2] + mass_2 * point_mass_2[2]))

Lagrangian = T - V




dLd_q = sp.Matrix([sp.diff(Lagrangian, qi) for qi in q])
dLd_dq = sp.Matrix([sp.diff(Lagrangian, dqi) for dqi in d_q])

d_dt_dLd_dq = dLd_dq.jacobian(q) @ d_q + dLd_dq.jacobian(d_q) @ dd_q

EOM = d_dt_dLd_dq - dLd_q - Q

M = d_dt_dLd_dq.jacobian(dd_q)
b = sp.simplify(d_dt_dLd_dq - M @ dd_q - dLd_q - Q)
print(M)
print(b)