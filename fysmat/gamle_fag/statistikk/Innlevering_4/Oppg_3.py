
# Oppg 3


import numpy as np
import matplotlib.pyplot as plt
import statsmodels.api as sm

n = 42
m = 35
r = 1000
lambda_ = 12

def alpha(n, m):
    return 1-(m/(4*n*m+2*n))
def beta(n, m):
    return m/(2*n*m+n)


def simuler(n, m, lambda_):
    a = alpha(n, m)
    b = beta(n, m)
    x_avg = np.average(np.random.poisson(lambda_, size=n))
    y_avg = np.average(np.random.poisson(lambda_/2, size=m))
    return  a*x_avg + b * y_avg


if __name__ == "__main__":
    lambda_estim = np.zeros(r)

    for i in range(r):
        lambda_estim[i] = simuler(n, m, lambda_)
    
    plt.hist(lambda_estim, bins=25)
    sm.qqplot(lambda_estim)
    

    plt.show()