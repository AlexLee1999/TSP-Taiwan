import numpy as np
import pandas as pd
import shapefile as shp
import matplotlib.pyplot as plt
import seaborn as sns

# init visual style
sns.set(style='whitegrid', palette='pastel', color_codes=True)
sns.mpl.rc('figure', figsize=(10, 6))


shp_path = './mapdata202104280245/TOWN_MOI_1100415.shp'
sf = shp.Reader(shp_path)


def plot_map(sf):
    plt.figure(figsize=(9, 7))
    id = 0
    for shape in sf.shapeRecords():
        x = [i[0] for i in shape.shape.points[:]]
        y = [i[1] for i in shape.shape.points[:]]

        if min(x) < 118:
            print(id, shape)
            continue
        points = list(zip(x, y))
        visited = set()
        xx = []
        yy = []
        for p in points:
            if p in visited:
                plt.plot(xx, yy, "#b0b0b0", linewidth=0.7)
                xx = []
                yy = []
            else:
                xx.append(p[0])
                yy.append(p[1])
                visited.add(p)
        id += 1
    plt.show()


plot_map(sf)
