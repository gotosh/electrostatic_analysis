import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt


if __name__ == "__main__":
    print(__file__)
    file_path = "../result_1/Efield_y_result.txt"
    print(os.path.exists(file_path))
    data = np.loadtxt(file_path)
    plt.figure(figsize=(10, 8))
    plt.imshow(data, cmap='jet', aspect='auto')
    plt.colorbar(label='Field Intensity')
    plt.title("Electric field (y direction) visualization")
    plt.xlabel("X-axis")
    plt.ylabel("Y-axis")
    plt.show()