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
x = np.arange(0.0, 100.0, 0.01)
y = np.sqrt(x)
df1 = pd.read_csv('data/fitting.csv')

#
#plt.plot(x, y, 'k-s', label=r'L = 8')
plt.plot(df1['N'], 2*df1['SD'], 'k-o', label='experiment')
plt.plot(x, y, 'r-', label=r'Y = $\sqrt{X}$')

#
plt.xlabel(r'$N$', fontsize=18) #$\Delta$
plt.ylabel(r'$width$', fontsize=18)
plt.legend() #show legend
plt.grid(linestyle='--') #grid line
plt.show()
