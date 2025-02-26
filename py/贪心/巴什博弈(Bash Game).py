# 巴什博弈(Bash Game)
# 一共有n颗石子，两个人轮流拿，每次可以拿1~m颗石子
# 拿到最后一颗石子的人获胜，根据n、m返回谁赢
import random
from tqdm import tqdm

def bashGame1(n, m):
    if n == 0:
        return "后手"
    if dp[n][m] != None:
        return dp[n][m]
    ans = "后手"
    for pink in range(1, m + 1):
        # 后续过程的赢家是后续过程的后手
		# 那就表示此时的先手，通过这个后续过程，能赢
        if bashGame1(n - pink, m) == "后手":
            ans = "先手"
            break
    dp[n][m] = ans
    return ans
# 正式方法
def bashGame2(n, m):
    return "先手" if n % (m + 1) != 0 else "后手"


if __name__ == '__main__':
    N = 500
    epochs = 10000
    print("测试开始！")
    for _ in tqdm(range(epochs)):
        n = random.randint(1, N)
        m = random.randint(1, N)
        dp = [[None] * (m + 1) for _ in range(n + 1)]
        if bashGame1(n, m) != bashGame2(n, m):
            print("出错了！")
            break
    print("测试结束！")
