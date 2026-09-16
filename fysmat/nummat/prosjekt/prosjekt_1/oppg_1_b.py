import numpy as np
import matplotlib.pyplot as plt

def runge_func(x_nodes):
    return 1/(x_nodes**2+1)


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


def finish_display():
    plt.legend()
    plt.grid()
    plt.show()













def norm_max(f, x_values):
    return np.max(np.abs(f(x_values)))

def norm_2(f, x_values):
    return np.sqrt(x_values[-1]-x_values[0])/np.sqrt(len(x_values)) * np.sqrt(np.sum(f(x_values)**2))


def interpolation_error_norm(f, p_n, norm, x_values):
    diff = lambda x: f(x) - p_n(x)
    return norm(diff, x_values)

def construct_p_n_function(x_nodes, y_nodes):
    return lambda x: lagrange_interpolation_array(x_nodes, y_nodes, x)




def error_norm_from_nodes(f, x_nodes, norm, x_count):

    p_n = construct_p_n_function(x_nodes, f(x_nodes))

    x_values = np.linspace(np.min(x_nodes), np.max(x_nodes), x_count)


    return interpolation_error_norm(f, p_n, norm, x_values)



def display_error_norm(f, x_interval, node_type, norm, node_counts, label=None):
    error_norms = []
    for n in node_counts:
        x_nodes = rescale(node_type(n), x_interval[0], x_interval[-1])

        e_norm = error_norm_from_nodes(f, x_nodes, norm, 1000)
        error_norms.append(e_norm)
    plt.plot(node_counts, error_norms, label=label)
    plt.xlabel("node count")
    plt.ylabel("error norm, $||f(x) - p_n(x)||$")

    


if __name__=="__main__":


    display_error_norm(runge_func, (-1, 1), equidistant_nodes, norm_2, np.array([10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]), label="equdistant | 2-norm")
    display_error_norm(runge_func, (-1, 1), equidistant_nodes, norm_max, np.array([10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]), label="equdistant | max-norm")
    display_error_norm(runge_func, (-1, 1), chubychub_nodes, norm_2, np.array([10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]), label="chebishev | 2-norm")
    display_error_norm(runge_func, (-1, 1), chubychub_nodes, norm_max, np.array([10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]), label="chebishev | max-norm")
    finish_display()