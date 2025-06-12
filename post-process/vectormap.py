import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.family'] = 'serif'
plt.rcParams['font.serif'] = ['Times New Roman'] + plt.rcParams['font.serif']
plt.rcParams['font.size'] = 16
if __name__ == "__main__":
    """
    Result_prev is the result of electrostatic analysis about previous electrode.
    """

    Efield_x = pd.read_csv('./result/Efield_x_result.txt', sep='\s+', header=None, index_col=None).values
    Efield_y = pd.read_csv('./result/Efield_y_result.txt', sep='\s+', header=None, index_col=None).values
    print(Efield_x)
    print(Efield_y)
    x = np.linspace(-100, 100, 1000)
    y = np.linspace(55, -45, 500)
    X, Y = np.meshgrid(x, y)
    C = np.sqrt(Efield_x**2 + Efield_y**2)
    fig, ax = plt.subplots()

    # plt.style.use('dark_background')
    
    q = ax.quiver(X[::16, ::16], Y[::16, ::16], Efield_x[::16, ::16], Efield_y[::16, ::16], C[::16, ::16],
               cmap = 'jet')

    cbar = plt.colorbar(q, ax = ax, label = "field intensity")
    cbar.set_label('Electric field [kV/mm]', rotation = 270, labelpad = 15)
    # plt.savefig("image.png")
    plt.show()
    print(X)

    