import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-2, 2, 1000)
y = x * np.exp(-np.abs(x))
plt.plot(x, y)
plt.show()