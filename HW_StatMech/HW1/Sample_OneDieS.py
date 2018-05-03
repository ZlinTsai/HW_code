import random
import time

def OneDieS(trials, sides):
    c1=time.clock()
    print("====================")
    print("Number of sides = ", sides)
    print("Number of trials = ", trials)

    histogram = []
    for s in range(sides):
        histogram.append(0)
    print(histogram)

    r = 0
    for t in range(trials):
        r = int(random.random()*sides)
        histogram[r] = histogram[r] + 1
    print( histogram)


    print("s, N_s, N_s-N/sides, N_s/N, N_s/N-1/sides")
    for s in range(sides):
        print(s+1, histogram[s], histogram[s]-trials/sides, histogram[s]/trials, histogram[s]/trials-1/sides)

    c2=time.clock()
    print("Elapsed time =", c2-c1)

def run():
    OneDieS(1, 6)
    OneDieS(10, 6)
    OneDieS(100, 6)
    OneDieS(1000, 6)
    OneDieS(10000, 6)
    OneDieS(100000, 6)
    OneDieS(1000000, 6)

run()
