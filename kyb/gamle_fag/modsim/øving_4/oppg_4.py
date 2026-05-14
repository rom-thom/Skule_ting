import sympy as sp
# Symbolic variables
L1, L2 = sp.symbols('L1 L2', real=True)
t = sp.symbols("t", real=True)
q1 = sp.Function("q1")(t)
q2 = sp.Function("q2")(t)

dq1, dq2 = sp.symbols('dq1 dq2', real=True)
# Vectors in terms of "local" reference frames
r1_B_A = sp.Matrix([L1, 0, 0])
r2_C_B = sp.Matrix([L2, 0, 0])
# Rotation transformation matrices
# Rz(q1)
R0_1 = sp.Matrix([
[sp.cos(q1), -sp.sin(q1), 0],
[sp.sin(q1), sp.cos(q1), 0],
[0, 0, 1]
])
# Ry(q2)
R1_2 = sp.Matrix([
[ sp.cos(q2), 0, sp.sin(q2)],
[ 0, 1, 0 ],
[-sp.sin(q2), 0, sp.cos(q2)]
])


def cros_vect(Omega):
    # Omega is a 3x3 skew matrix
    return sp.Matrix([
        Omega[2, 1],  # wx
        Omega[0, 2],  # wy
        Omega[1, 0],  # wz
    ])



# Composite rotation
R0_2 = R0_1 * R1_2

r0_B_A = R0_1 * r1_B_A

r0_C_A = r0_B_A + R0_2*r2_C_B

w0_1_0 = cros_vect(sp.simplify(sp.diff(R0_1, t) * sp.transpose(R0_1)))

w1_2_1 = cros_vect(sp.simplify(sp.diff(R1_2, t) * sp.transpose(R1_2)))
w0_2_1 = R0_1 * w1_2_1 + w0_1_0


v0_1_0 = w0_1_0.cross(r0_B_A)
v0_2_0 = w0_2_1.cross(r0_C_A)

print(v0_2_0)
