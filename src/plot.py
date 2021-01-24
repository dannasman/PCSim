import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
import pandas as pd

data1 = pd.read_csv("./particle1.csv")
data2 = pd.read_csv("./particle2.csv")
data3 = pd.read_csv("./particle3.csv")

fig = plt.figure()
ax = fig.add_subplot(111, projection = '3d')
for i in range(len(data1.values)):
    ax.plot(data1.values[i][0], data1.values[i][1], data1.values[i][2], c='b', marker = 'x')
    ax.plot(data2.values[i][0], data2.values[i][1], data2.values[i][2], c='r', marker = 'x')
    ax.plot(data3.values[i][0], data3.values[i][1], data3.values[i][2], c='r', marker = 'x')
plt.show()