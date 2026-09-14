



def lagrange_interpolation(x_nodes, y_nodes, x_values):
    if len(x_nodes != y_nodes):
        raise IndexError("Size of x_nodes and y_nodes should be the same")
    
    n = len(x_nodes) - 1

    def q_i(x, x_nodes, i):
        if i < 0 or i > n:
            raise IndexError("Indexen er utanfor node-talet")

        q = 1
        for nr in range(len(x_nodes)):
            if nr == int(i):
                continue
            q *= x - x_nodes[nr]
        return q

    y_values = []
    for x in x_values:

        y_values.append(sum([y_nodes[nr] * q_i(x, x_nodes, nr)/(q_i(x_nodes[nr], x_nodes, nr)) for nr in range(len(x_nodes))]))
    return y_values






x_nodes = [-2, -1, 1, 3]
y_nodes = [-1, -2, 2, 14]


print(lagrange_interpolation(x_nodes, y_nodes, [0]))    # -1
print(lagrange_interpolation(x_nodes, y_nodes, [2]))    # 7
print(lagrange_interpolation(x_nodes, y_nodes, [4]))    # 23