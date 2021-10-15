# TSP-Taiwan
## Introduction
In this project, I use three algorithms to approximate the Travelling Salesman Problem (TSP) with data from Taiwan.

## Algorithms 
### Nearest Neighbor
This algorithm always choose the nearest unvisited neighbour as the next destination.  

### Minimum Spanning Tree
The algorithm first calculate the Minimum Spanning Tree (MST), and sort the sequence of destinations with preorder traversal.
### Branch and Bound

## Distances between Cities
The data between counties are measured with Google Maps, and I use the government building as the exact point to measure the distance between counties.
| | Taipei     | New-Taipei | Keelung | Taoyuan | Hsinchu | Maoli  | Taichung | Changhua | Nantou | Yunlin | Chiayi | Tainan | Kaohsiung | Pingtung | Yilan  | Hualien | Taidung |
|:----------:|:----------:|:-------:|:-------:|:-------:|:------:|:--------:|:--------:|:------:|:------:|:------:|:------:|:---------:|:--------:|:------:|:-------:|:-------:|:------:|
| Taipei     | 0          | 10.37   | 20.92   | 27      | 65.32  | 91.67    | 134.54   | 148.64 | 154.14 | 182.26 | 206.51 | 267.16    | 297.47   | 283.82 | 39.67   | 117.53  | 257.27 |
| New-Taipei | 10.37      | 0       | 31.09   | 16.72   | 55.05  | 81.93    | 125.68   | 139.74 | 146.2  | 174.27 | 198.76 | 259.55    | 290.71   | 277.43 | 43.37   | 114.57  | 252.96 |
| Keelung    | 20.92      | 31.09   | 0       | 47.27   | 86.13  | 112.53   | 154.76   | 168.87 | 173.34 | 201.44 | 225.37 | 285.79    | 314.94   | 300.75 | 44.62   | 127.46  | 271.02 |
| Taoyuan    | 27         | 16.72   | 47.27   | 0       | 39.34  | 67.92    | 113.64   | 127.49 | 136.05 | 163.84 | 188.75 | 249.67    | 282.35   | 269.83 | 55.03   | 115.95  | 249.72 |
| Hsinchu    | 65.32      | 55.05   | 86.13   | 39.34   | 0      | 30.78    | 78.8     | 91.95  | 104.41 | 131.06 | 156.38 | 216.95    | 252.15   | 241.17 | 80.63   | 112.11  | 228.83 |
| Maoli      | 91.67      | 81.93   | 112.53  | 67.92   | 30.78  | 0        | 48.16    | 61.19  | 74.81  | 100.78 | 126.15 | 186.45    | 222.34   | 211.98 | 97.01   | 102.99  | 203.98 |
| Taichung   | 134.54     | 125.68  | 154.76  | 113.64  | 78.8   | 48.16    | 0        | 14.13  | 29.13  | 52.86  | 78.16  | 138.3     | 174.77   | 165.21 | 129.51  | 100.39  | 164.57 |
| Changhua   | 148.64     | 139.74  | 168.87  | 127.49  | 91.95  | 61.19    | 14.13    | 0      | 24.31  | 41.89  | 66.75  | 125.9     | 163.57   | 154.96 | 143.33  | 109.49  | 159.28 |
| Nantou     | 154.14     | 146.2   | 173.34  | 136.05  | 104.41 | 74.81    | 29.13    | 24.31  | 0      | 28.12  | 52.72  | 113.61    | 147.71   | 137.19 | 142.44  | 94.75   | 135.92 |
| Yunlin     | 182.26     | 174.27  | 201.44  | 163.84  | 131.06 | 100.78   | 52.86    | 41.89  | 28.12  | 0      | 25.34  | 85.97     | 121.95   | 113.07 | 169.96  | 115.83  | 122.77 |
| Chiayi     | 206.51     | 198.76  | 225.37  | 188.75  | 156.38 | 126.15   | 78.16    | 66.75  | 52.72  | 25.34  | 0      | 60.9      | 96.82    | 88.84  | 192.27  | 131.54  | 107.65 |
| Tainan     | 267.16     | 259.55  | 285.79  | 249.67  | 216.95 | 186.45   | 138.3    | 125.9  | 113.61 | 85.97  | 60.9   | 0         | 43.36    | 46.31  | 251.21  | 183.68  | 103.32 |
| Kaohsiung  | 297.47     | 290.71  | 314.94  | 282.35  | 252.15 | 222.34   | 174.77   | 163.57 | 147.71 | 121.95 | 96.82  | 43.36     | 0        | 19.33  | 277.36  | 202.64  | 87.3   |
| Pingtung   | 283.82     | 277.43  | 300.75  | 269.83  | 241.17 | 211.98   | 165.21   | 154.96 | 137.19 | 113.07 | 88.84  | 46.31     | 19.33    | 0      | 262.11  | 185.77  | 68.43  |
| Yilan      | 39.67      | 43.37   | 44.62   | 55.03   | 80.63  | 97.01    | 129.51   | 143.33 | 142.44 | 169.96 | 192.27 | 251.21    | 277.36   | 262.11 | 0       | 83.5    | 228.3  |
| Hualien    | 117.53     | 114.57  | 127.46  | 115.95  | 112.11 | 102.99   | 100.39   | 109.49 | 94.75  | 115.83 | 131.54 | 183.68    | 202.64   | 185.77 | 83.5    | 0       | 145.51 |
| Taidung    | 257.27     | 252.96  | 271.02  | 249.72  | 228.83 | 203.98   | 164.57   | 159.28 | 135.92 | 122.77 | 107.65 | 103.32    | 87.3     | 68.43  | 228.3   | 145.51  | 0      |


## Results
### Nearest Neighbour Algorithm
#### Google Map Plot
<img src="NN_Result.png" width="300">

#### Sequence
Total Distance : 723.84 km  
Taipei -> New Taipei -> Taoyuan -> Hsinchu -> Maoli -> Taichung -> Changhua -> Nantou -> Yunlin -> Chiayi -> Tainan -> Kaohsiung -> Pingtung -> Taitung -> Hualien -> Yilan -> Keelung -> Taipei

### Minimum Spanning Tree Approximate Algorithm
#### Google Map Plot
<img src="MST_Result.png" width="300">  

#### Sequence
Total Distance : 957.91  km  
Taipei -> Taitung -> Pingtung ->  Kaohsiung -> Tainan -> Chiayi -> Yunlin -> Nantou -> Changhua -> Taichung -> Maoli -> Hsinchu -> Taoyuan -> New Taipei -> Keelung -> Hualien -> Yilan -> Taipei
