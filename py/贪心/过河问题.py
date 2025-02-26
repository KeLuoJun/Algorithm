# 过河问题
# 一共n人出游，他们走到一条河的西岸，想要过河到东岸
# 每个人都有一个渡河时间ti，西岸有一条船，一次最多乘坐两人
# 如果船上有一个人，划到对岸的时间，等于这个人的渡河时间
# 如果船上有两个人，划到对岸的时间，等于两个人的渡河时间的最大值
# 返回最少要花费多少时间，才能使所有人都过河
# 测试链接 : https://www.luogu.com.cn/problem/P1809

import sys
def solve(n, t: list):
    t.sort()
    dp = [0] * n
    if n >= 1:
        dp[0] = t[0]
    if n >= 2:
        dp[1] = t[1]
    if n >= 3:
        dp[2] = t[0] + t[1] + t[2]
    for i in range(3, n):
        # 第一种：剩t[i]在对岸，t[0]回去把t[i]接过来
        # 第二种：剩t[i-1] 和 t[i] 在对岸，t[1]过去，t[i-1]和t[i]一起过来，再由t[0]过去把t[1]接过来
        dp[i] = min(dp[i - 1] + t[0] + t[i], dp[i - 2] + t[1] + t[i] + t[0] + t[1])
    return dp[n - 1]

if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    t = list(map(int, data[1:]))
    print(solve(n, t))
