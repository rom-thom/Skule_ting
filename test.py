import random





def simuler():
    prob = [0.02, 0.03, 0.15, 0.25, 0.35, 0.2]
    vals = [1-4.6, 2-4.6, 3-4.6, 4-4.6, 5-4.6, 6-4.6]
    return sum(random.choices(vals, weights=prob, k=50))



N = 100000
count = 0
for i in range(N):
    if simuler() >= 0:
        count += 1

print(count/N)
