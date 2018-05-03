import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.mathtext
from   matplotlib.ticker import MultipleLocator

# set picture parameter
fig, ax = plt.subplots()
plt.tick_params(which='major', direction='in', length=7)
plt.tick_params(top='on',bottom='on',left='on',right='on')
#mlx = MultipleLocator(0.5)
#mly = MultipleLocator(0.05)
#ax.xaxis.set_minor_locator(mlx)
#ax.yaxis.set_minor_locator(mly)
plt.tick_params(which='minor', direction='in', length=4)

# set dataframe
df1 = pd.read_csv('data/ND_10_NS_2.csv')
df2 = pd.read_csv('data/ND_20_NS_2.csv')
df3 = pd.read_csv('data/ND_40_NS_2.csv')
df4 = pd.read_csv('data/ND_60_NS_2.csv')
df5 = pd.read_csv('data/ND_80_NS_2.csv')
df6 = pd.read_csv('data/ND_100_NS_2.csv')

#
#plt.plot(x, y, 'k-s', label=r'L = 8')
trials = 10000
plt.plot(df1['S'], df1['Prob(S)']/trials, 'k-o', label=r'N = 10')
plt.plot(df2['S'], df2['Prob(S)']/trials, 'r-o', label=r'N = 20')
plt.plot(df3['S'], df3['Prob(S)']/trials, 'g-o', label=r'N = 40')
plt.plot(df4['S'], df4['Prob(S)']/trials, 'b-o', label=r'N = 60')
plt.plot(df5['S'], df5['Prob(S)']/trials, 'y-o', label=r'N = 80')
plt.plot(df6['S'], df6['Prob(S)']/trials, 'c-o', label=r'N = 100')

#
plt.xlabel(r'$S/<S>$', fontsize=18) #$\Delta$
plt.ylabel(r'$P(S)$', fontsize=18)
plt.title(r'Probability distribution with different N', fontsize=20)
plt.legend() #show legend
plt.grid(linestyle='--') #grid line
plt.show()
