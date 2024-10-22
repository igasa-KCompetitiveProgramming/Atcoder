import math

n = int(input())  # 点の数を入力
x = []
y = []

for i in range(n):
    xi, yi = map(int, input().split())  # 点の座標を入力
    x.append(xi)
    y.append(yi)

ans = 0
nx, ny = 0, 0  # 原点からスタート

for i in range(n):
    ans += math.sqrt((x[i] - nx) ** 2 + (y[i] - ny) ** 2)  # 距離を計算
    nx = x[i]
    ny = y[i]

# 最後に原点に戻る距離を計算
ans += math.sqrt(nx ** 2 + ny ** 2)

print(ans)
