from distance import formula_distance
import pandas
import json

if __name__ == "__main__":
    df = pandas.read_csv("./town.csv")
    towns_nums = 371
    df = df.drop(["行政區名", "TGOS_URL"], axis=1)
    dic = {}
    for i in range(371):
        dic[i] = f'{df["_x0033_碼郵遞區號"][i]}'
    with open("code.json", "w") as fp:
        json.dump(dic, fp)
    df = df.drop(["_x0033_碼郵遞區號"], axis=1)
    print(df)
    f = open("town_distance.txt", "w")
    f.write(f"{towns_nums}" + "\n")
    for i in range(towns_nums):
        for j in range(i + 1, towns_nums):
            dis = formula_distance(
                df["中心點經度"][i], df["中心點經度"][j], df["中心點緯度"][i], df["中心點緯度"][j]
            )
            f.write(f"{i} {j} {dis}" + "\n")
