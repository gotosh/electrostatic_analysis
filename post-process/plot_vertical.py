import os
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def burner_outlet_to_coordinate(distance_from_outlet):
    return 55 - distance_from_outlet

def plot_electric_field(file_path):
    data = np.loadtxt(file_path)
    print(np.shape(data))
    x_coordinate = np.linspace(-100, 100, len(data[0, :]))
    plt.figure(figsize=(10, 5))
    plt.plot(x_coordinate, data[int(burner_outlet_to_coordinate(7.5)), :], label = "7.5 mm")
    plt.plot(x_coordinate, data[burner_outlet_to_coordinate(10), :], label = "10 mm")
    plt.plot(x_coordinate, data[int(burner_outlet_to_coordinate(12.5)), :], label = "12.5 mm")
    plt.plot(x_coordinate, data[burner_outlet_to_coordinate(15), :], label = "15 mm")
    plt.xlim(-30, 30)
    plt.ylim(0.25, 0.45)
    plt.xlabel("x")
    plt.ylabel("Electric field strength [kV/mm]")
    plt.legend()
    plt.show()

if __name__ == "__main__":
    
    plot_electric_field(file_path="./result/Efield_y_result.txt")
    plot_electric_field(file_path="./result_boundary_1/Efield_y_result.txt")

