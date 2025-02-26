# 观赏樱花 
# 给定一个背包的容量t，一共有n种货物，并且给定每种货物的信息
# 花费(cost)、价值(val)、数量(cnt)
# 如果cnt == 0，代表这种货物可以无限选择
# 如果cnt > 0，那么cnt代表这种货物的数量
# 挑选货物的总容量在不超过t的情况下，返回能得到的最大价值
# 背包容量不超过1000，每一种货物的花费都>0
# 测试链接 : https://www.luogu.com.cn/problem/P1833

from datetime import datetime

def compute():
    dp = [0] * (t + 1)
    for i in range(1, m + 1):
        for j in range(t, w[i] - 1, -1):
            dp[j] = max(dp[j], dp[j - w[i]] + v[i])
    return dp[t]


time1, time2, n = input().split()
time1 = datetime.strptime(time1, '%H:%M')
time2 = datetime.strptime(time2, '%H:%M')
t = int((time2 - time1).total_seconds() // 60)

n = int(n)
m = 0  # 分组后的物品数量
v = [0] 
w = [0]
for i in range(1, n + 1):
    ww, vv, cnt = list(map(int, input().split()))
    cnt = 1000 if cnt == 0 else cnt
    k = 1
    while k <= cnt:
        m += 1
        v.append(k * vv)
        w.append(k * ww)
        cnt -= k
        k <<= 1
    if cnt > 0:
        m += 1
        v.append(vv * cnt)
        w.append(ww * cnt)

print(compute())

