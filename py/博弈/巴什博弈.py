# 巴什博弈(Bash Game)
# 一共有n颗石子，两个人轮流拿，每次可以拿1~m颗石子
# 拿到最后一颗石子的人获胜，根据n、m返回谁赢

import random
# 动态规划
def bashGame1(n, m, dp):
    if n == 0:
        return "后手"

    if dp[n][m] != None:
        return dp[n][m]

    ans = "后手"
    for i in range(1, m + 1):
        if bashGame1(n - i, m, dp) == "后手":
            ans = "先手"
            break

    dp[n][m] = ans
    return ans


# 正式方法
def bashGame2(n, m):
    return "后手" if n % (m + 1) == 0 else "先手"


def main() -> None:
    V = 500
    testTimes = 1000
    print("测试开始")
    for i in range(testTimes):
        n = int(random.random() * V)
        m = int(random.random() * V) + 1
        dp = [[None] * (m + 1) for _ in range(n + 1)]
        ans1 = bashGame1(n, m, dp)
        ans2 = bashGame2(n, m)
        if ans1 != ans2:
            print("出错了！")
            print(n, m)
    print("测试结束")

if __name__ == '__main__':
    main()
