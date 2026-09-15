import numpy as np
import oppg_1_a





def norm_max(f, x_values):
    return np.max(np.abs(f(x_values)))

def norm_2(f, x_values):
    return np.sqrt(x_values[-1]-x_values[0])/np.sqrt(len(x_values)) * np.sqrt(np.sum(f(x_values)**2))


def interpolation_error(f, p_n, norm, x_values):
    diff = lambda x: f(x) - p_n(x)
    return norm(diff, x_values)

def construct_p_n_function(x_nodes, y_nodes):
    return lambda x: lagrange_interpolation_array(x_nodes, y_nodes, x)


def display_error_norm(f, x_nodes, norm, label=None, show_nodes=False):

    p_n = construct_p_n_function(x_nodes, f(x_nodes))

    