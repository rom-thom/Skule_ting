import numpy as np
import matplotlib.pyplot as plt
from scipy.stats import norm


def corr(theta_1, theta_2):
    return (1 + 15 * np.abs(theta_2 - theta_1)) * np.exp(-15 * np.abs(theta_2 - theta_1))


def a(theta_obs, y_obs):
    grid_vals = np.linspace(0.25, 0.5, 51)

    mean_grid = np.full(51, 0.5)
    mean_obs = np.full(len(theta_obs), 0.5)

    # Covariance matrix between grid points, observations, and the two sets.
    cov_grid = 0.5**2 * corr(grid_vals[:, None], grid_vals[None, :])
    cov_obs = 0.5**2 * corr(theta_obs[:, None], theta_obs[None, :])
    cov_cross = 0.5**2 * corr(grid_vals[:, None], theta_obs[None, :])

    # Conditional mean and covariance given the observations.
    mean_cond = mean_grid + cov_cross @ np.linalg.solve(cov_obs, y_obs - mean_obs)
    cov_cond = cov_grid - cov_cross @ np.linalg.solve(cov_obs, cov_cross.T)

    std_cond = np.sqrt(np.maximum(np.diag(cov_cond), 0))
    lower = mean_cond - norm.ppf(0.95) * std_cond
    upper = mean_cond + norm.ppf(0.95) * std_cond

    plt.figure()
    plt.plot(grid_vals, mean_cond, label="Conditional mean")
    plt.fill_between(grid_vals, lower, upper, alpha=0.4, label="90% prediction interval")
    plt.scatter(theta_obs, y_obs, label="Observations")
    plt.xlabel(r"$\theta$")
    plt.ylabel(r"$Y(\theta)$")
    plt.title(f"Prediction given {len(theta_obs)} observations")
    plt.legend()
    plt.tight_layout()
    return grid_vals, mean_cond, std_cond


def b(grid_vals, mean_cond, std_cond):
    # Use the gausian CDF when the point is not known 
    probability = (mean_cond < 0.30).astype(float)
    uncertain = std_cond > 0
    probability[uncertain] = norm.cdf((0.30 - mean_cond[uncertain]) / std_cond[uncertain])

    plt.figure()
    plt.plot(grid_vals, probability)
    plt.xlabel(r"$\theta$")
    plt.ylabel(r"$P(Y(\theta) < 0.30 \mid \mathrm{observations})$")
    plt.tight_layout()
    return probability


def c(theta_obs, y_obs):
    theta_obs = np.append(theta_obs, 0.33)
    y_obs = np.append(y_obs, 0.40)

    # Gjenta a og b med den nye verdien
    grid_vals, mean_cond, std_cond = a(theta_obs, y_obs)
    probability = b(grid_vals, mean_cond, std_cond)

    best = np.argmax(probability)
    plt.scatter(grid_vals[best], probability[best], label=fr"Suggested $\theta = {grid_vals[best]:.3f}$")
    plt.legend()
    print(f"Suggested theta: {grid_vals[best]:.3f}")
    print(f"Probability of Y(theta) < 0.30: {probability[best]:.3f}")
    print("This gives the highest probability of a score below 0.30 on the grid.")


if __name__ == "__main__":
    theta_obs = np.array([0.30, 0.35, 0.39, 0.41, 0.45])
    y_obs = np.array([0.5, 0.32, 0.40, 0.35, 0.60])

    grid_vals, mean_cond, std_cond = a(theta_obs, y_obs)
    b(grid_vals, mean_cond, std_cond)
    c(theta_obs, y_obs)
    plt.show()
