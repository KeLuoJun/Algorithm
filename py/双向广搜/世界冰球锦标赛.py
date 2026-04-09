# 牛牛的背包问题 & 世界冰球锦标赛
# 牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
# 牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
# 牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
# 输入描述：
# 输入包括两行
# 第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量
# 第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积
# 输出描述：
# 输出一个正整数, 表示牛牛一共有多少种零食放法。
# 测试链接 : https://www.luogu.com.cn/problem/P4799

import sys

def compute(n, w, arr):
    """计算所有子集和不超过w的方案数"""
    if w < 0:
        return 0
    def dfs(i, e, s, w, res):
        if s > w:
            return
        if i == e:
            res.append(s)
        else:
            dfs(i + 1, e, s, w, res)
            dfs(i + 1, e, s + arr[i], w, res)
    l_sum, r_sum = [], []
    dfs(0, n >> 1, 0, w, l_sum)
    dfs(n >> 1, n, 0, w, r_sum)
    l_sum.sort(), r_sum.sort()
    ans = 0
    j = 0
    for i in range(len(l_sum) - 1, -1, -1):
        while j < len(r_sum) and l_sum[i] + r_sum[j] <= w:
            j += 1
        ans += j
    return ans
        
def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n, m = data[0], data[1]
    arr = data[2:2 + n]
    print(compute(n, m, arr))


if __name__ == '__main__':
    main()

