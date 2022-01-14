import numpy as np
import pandas
import shapefile as shp
import matplotlib.pyplot as plt
import seaborn as sns

# init visual style
sns.set(style='whitegrid', palette='pastel', color_codes=True)
sns.mpl.rc('figure', figsize=(10, 6))

data_path = '../data'
shp_path = data_path + '/mapdata202104280245/TOWN_MOI_1100415.shp'
# shp_path = data_path + '/mapdata202008310842/COUNTY_MOI_1090820.shp'
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
                if min(xx) > 123:
                    plt.plot(xx, yy, "white", linewidth=0.7)
                else:
                    plt.plot(xx, yy, "k", linewidth=0.7)
                xx = []
                yy = []
            else:
                xx.append(p[0])
                yy.append(p[1])
                visited.add(p)
        id += 1
    df = pandas.read_csv(data_path + "/town_data.csv")
    df = df.drop(["行政區名", "TGOS_URL"], axis=1)
    df = df.drop(["_x0033_碼郵遞區號"], axis=1)
    plt.scatter(df['中心點經度'], df['中心點緯度'], 0.5, "#d0aab5")
    plt.savefig('../Taiwan_map.png')


plot_map(sf)
