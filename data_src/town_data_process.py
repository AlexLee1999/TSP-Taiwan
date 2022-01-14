from distance import formula_distance
import pandas
import json

if __name__ == "__main__":
    data_path = '../data'
    df = pandas.read_csv(data_path + "/town_data.csv")
    towns_nums = 349
    df = df.drop(["行政區名", "TGOS_URL"], axis=1)
    dic = {}
    for i in range(towns_nums):
        dic[i] = f'{df["_x0033_碼郵遞區號"][i]}'
    with open(data_path + "/code.json", "w") as fp:
        json.dump(dic, fp)
    df = df.drop(["_x0033_碼郵遞區號"], axis=1)
    f = open("../town_distance.txt", "w")
    f.write(f"{towns_nums}" + "\n")
    for i in range(towns_nums):
        for j in range(i + 1, towns_nums):
            dis = formula_distance(
                df["中心點經度"][i], df["中心點經度"][j], df["中心點緯度"][i], df["中心點緯度"][j]
            )
            f.write(f"{i} {j} {dis}" + "\n")

    dic = {}
    for i in range(towns_nums):
        sub_dic = {}
        
        sub_dic['la'] = f'{df["中心點經度"][i]}'
        sub_dic['lo'] = f'{df["中心點緯度"][i]}'
        dic[i] = sub_dic
    with open(data_path + "/place.json", "w") as fp:
        json.dump(dic, fp)