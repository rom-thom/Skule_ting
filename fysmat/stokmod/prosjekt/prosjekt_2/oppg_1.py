






def b():
    import numpy as np
    import matplotlib.pyplot as plt
    from scipy import stats

    # Parameters (hours)
    lam = 5
    mu = 6
    T = 50 * 24

    def simulate():
        # Part 1

        # Simulate arrivals
        arrivals = []
        t = 0

        while t < T:
            t += np.random.exponential(1 / lam)
            if t <= T:
                arrivals.append(t)

        # Simulate treatment times
        services = np.random.exponential(1 / mu, len(arrivals))

        # Calculate departures
        departures = []
        last_departure = 0

        for i in range(len(arrivals)):
            start = max(arrivals[i], last_departure)
            departure = start + services[i]

            departures.append(departure)
            last_departure = departure

        # Combine arrivals and departures within 50 days
        events = []

        for t in arrivals:
            events.append((t, 1))

        for t in departures:
            if t <= T:
                events.append((t, -1))

        events.sort()

        # Construct X(t)
        times = [0]
        X = [0]

        for t, change in events:
            times.append(t)
            X.append(X[-1] + change)

        times.append(T)
        X.append(X[-1])

        # Part 2
        L = np.sum(np.array(X[:-1]) * np.diff(times)) / T
        E_S = L / lam

        return times, X, E_S


    # Part 3
    estimates = []

    for i in range(30):
        sim_times, sim_X, E_S = simulate()
        estimates.append(E_S)

        if i == 0:
            times = sim_times
            X = sim_X

    mean = np.mean(estimates)
    SE = stats.sem(estimates)

    CI = stats.t.interval(0.95, df=29, loc=mean, scale=SE)

    print("Estimated E[S]:", mean)
    print("95% CI:", CI)

    # Part 4
    # plot first 12 hours of the first simulation
    plt.step(times, X, where="post")
    plt.xlim(0, 12)
    plt.xlabel("Time (hours)")
    plt.ylabel("X(t)")
    plt.title("M/M/1 queue")
    plt.show()





def f():
    import numpy as np
    import matplotlib.pyplot as plt

    # Parameters (patients per hour)
    lam = 5
    mu = 6

    # Proportion of urgent patients
    p = np.linspace(0, 1, 1000)

    # Expected time in the UCC (hours)
    W_U = 1 / (mu - p * lam)
    W_N = mu / ((mu - lam) * (mu - p * lam))

    # Plot
    plt.figure(figsize=(8, 5))
    plt.plot(p, W_U, label=r"$W_U$ (Urgent)")
    plt.plot(p, W_N, label=r"$W_N$ (Normal)")

    plt.xlabel(r"Proportion of urgent patients $p$")
    plt.ylabel("Expected time in UCC (hours)")
    plt.title("Expected Time in UCC vs. Proportion of Urgent Patients")
    plt.legend()
    plt.grid()
    plt.tight_layout()

    plt.savefig("figure_1f.pdf")
    plt.show()


def g():
    import numpy as np
    import matplotlib.pyplot as plt

    lam = 5
    mu = 6
    p = 0.8
    T = 50 * 24
    n_sim = 30

    rng = np.random.default_rng(4265)

    def simulate(save_plot=False):
        t = 0
        U, N = 0, 0
        sum_U, sum_N = 0, 0
        intervals = []

        while t < T:
            rate_U = lam * p
            rate_N = lam * (1-p)
            rate_out = mu if U + N > 0 else 0
            rate = rate_U + rate_N + rate_out

            dt = rng.exponential(1/rate)
            next_t = min(t + dt, T)

            # Area under the two processes
            sum_U += U * (next_t - t)
            sum_N += N * (next_t - t)

            if save_plot and t < 12:
                intervals.append((t, min(next_t, 12), U, U+N))

            if t + dt >= T:
                break

            r = rng.uniform(0, rate)

            if r < rate_U:
                U += 1
            elif r < rate_U + rate_N:
                N += 1
            elif U > 0:
                U -= 1
            else:
                N -= 1

            t = next_t

        # Little's law
        W_U = sum_U / (T * lam * p)
        W_N = sum_N / (T * lam * (1-p))

        return W_U, W_N, intervals


    results = []
    first_intervals = []

    for i in range(n_sim):
        wu, wn, intervals = simulate(save_plot=(i == 0))
        results.append([wu, wn])

        if i == 0:
            first_intervals = intervals

    results = np.array(results)

    # Confidence intervals
    means = np.mean(results, axis=0)
    std = np.std(results, axis=0, ddof=1)

    t_crit = 2.04523
    margin = t_crit * std / np.sqrt(n_sim)

    print("Urgent patients:")
    print(f"Mean: {means[0]:.4f} hours")
    print(f"95% CI: [{means[0]-margin[0]:.4f}, {means[0]+margin[0]:.4f}]")

    print("\nNormal patients:")
    print(f"Mean: {means[1]:.4f} hours")
    print(f"95% CI: [{means[1]-margin[1]:.4f}, {means[1]+margin[1]:.4f}]")


    # First 12 hours
    fig, ax = plt.subplots(figsize=(9, 4.5))

    for i, (start, end, u, total) in enumerate(first_intervals):
        ax.hlines(total, start, end, color="tab:blue", linewidth=1.8,
                label="Total patients" if i == 0 else "_nolegend_")

        ax.hlines(u, start, end, color="tab:orange", linewidth=2.5,
                zorder=3, label="Urgent patients" if i == 0 else "_nolegend_")

    ax.set_xlabel("Time (hours)")
    ax.set_ylabel("Number of patients")
    ax.set_xlim(0, 12)
    ax.set_ylim(bottom=0)
    ax.legend()
    ax.grid(alpha=0.25)

    plt.tight_layout()
    plt.savefig("simulation_1g.pdf", bbox_inches="tight")
    plt.show()




if __name__ == "__main__":
    b()
    f()
    g()