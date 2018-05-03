import random
import time
import numpy as np

def OneDie_np(trials):
    c1=time.clock()
    print("====================")
    print("One die with 6 sides")
    print("Number of trials = ", trials)

    sides = 6
    histogram = np.zeros(sides)
    print(histogram)

    r = 0
    for j in range(trials):
        r = int(np.random.random()*sides) # Faster.
#         r = np.random.randint(0,5) # Slower. Return random integers from `low` (inclusive) to `high` (exclusive).
        histogram[r] = histogram[r] + 1

    print("s, N_s, N_s-N/6, N_s/N, N_s/N-1/6")

    for j in range(sides):
        print(j+1, histogram[j], histogram[j]-trials/sides, histogram[j]/trials, histogram[j]/trials-1/6)

    c2=time.clock()
    print("Elapsed time =", c2-c1)

def run():
    OneDie_np(1)
    OneDie_np(10)
    OneDie_np(100)
    OneDie_np(1000)
    OneDie_np(10000)
    OneDie_np(100000)
    OneDie_np(1000000)

run()
