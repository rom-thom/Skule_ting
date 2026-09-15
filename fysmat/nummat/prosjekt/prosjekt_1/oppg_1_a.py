import numpy as np
import matplotlib.pyplot as plt


def lagrange_interpolation_array(x_nodes, y_nodes, x):
    if len(x_nodes) != len(y_nodes):
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

    y = []
    for x in x:

        y.append(sum([y_nodes[nr] * q_i(x, x_nodes, nr)/(q_i(x_nodes[nr], x_nodes, nr)) for nr in range(len(x_nodes))]))
    return y


def equidistant_nodes(node_count = 50):
    return np.linspace(-1, 1, node_count)

def chubychub_nodes(node_count = 50):
    count_nr = np.arange(0, node_count)
    return np.cos(((count_nr+1/2)*np.pi)/(node_count))

def rescale(nodes, start, end):
    return (end-start)/2 * nodes + (end+start)/2




def runge_func(x_nodes):
    return 1/(x_nodes**2+1)




def display_interpolation(x_node_func, func, x_node_interval=(-1, 1), node_count=15, label=None, show_nodes=False):


    x_nodes = x_node_func(node_count)
    x_nodes = rescale(x_nodes, x_node_interval[0], x_node_interval[-1])
    y_nodes = func(x_nodes)

    x_vals = np.linspace(x_nodes[0], x_nodes[-1], 1000)
    
    y_interpolation_vals = lagrange_interpolation_array(x_nodes, y_nodes, x_vals)

    plt.plot(x_vals, y_interpolation_vals, label=label)

    if show_nodes:
        plt.scatter(x_nodes, y_nodes, label=label)



def finish_display():
    plt.legend()
    plt.grid()
    plt.show()




if __name__ == "__main__":
    display_interpolation(chubychub_nodes, runge_func, (-5, 5), label="chebichev", node_count=10, show_nodes=True)
    plt.plot(np.linspace(-5, 5, 1000), runge_func(np.linspace(-5, 5, 1000)), label="real")
    finish_display()
    display_interpolation(equidistant_nodes, runge_func, (-5, 5), label="equidistant", node_count=10, show_nodes=True)
    plt.plot(np.linspace(-5, 5, 1000), runge_func(np.linspace(-5, 5, 1000)), label="real")
    finish_display()

