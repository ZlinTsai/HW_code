import random
import time
import numpy as np

def OneDieS_np(trials, sides):
    c1=time.clock()
    print("====================")
    print("Number of sides = ", sides)
    print("Number of trials = ", trials)

    histogram = np.zeros(sides)
    print(histogram)

    r = 0
    for t in range(trials):
        r = int(np.random.random()*sides)
        histogram[r] = histogram[r] + 1
    print(histogram)


    print("s, N_s, N_s-N/sides, N_s/N, N_s/N-1/sides")
    for s in range(sides):
        print(s+1, histogram[s], histogram[s]-trials/sides, histogram[s]/trials, histogram[s]/trials-1/sides)

    c2=time.clock()
    print("Elapsed time =", c2-c1)

def run():
    OneDieS_np(1, 6)
    OneDieS_np(10, 6)
    OneDieS_np(100, 6)
    OneDieS_np(1000, 6)
    OneDieS_np(10000, 6)
    OneDieS_np(100000, 6)
    OneDieS_np(1000000, 6)

run()
