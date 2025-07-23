# 火柴拼正方形
# 你将得到一个整数数组 matchsticks
# 其中 matchsticks[i] 是第 i 个火柴棒的长度
# 你要用 所有的火柴棍 拼成一个正方形
# 你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次
# 如果你能拼出正方形，则返回 true ，否则返回 false
# 测试链接 : https://leetcode.cn/problems/matchsticks-to-square/


import sys
from typing import List

def makesquare(matchsticks: List[int], k: int) -> bool:
    n = len(matchsticks)
    Sum = sum(matchsticks)
    if Sum % k != 0:
        return False
    dp = [0] * (1 << n)

    def f(limit, status, cur, rest):
        """
        limit : 每条边规定的长度
        status : 表示哪些数字还可以选
        cur : 当前要解决的这条边已经形成的长度
        rest : 一共还有几条边没有解决
        返回 : 能否用光所有火柴去解决剩下的所有边
        因为调用子过程之前，一定保证每条边累加起来都不超过limit
        所以status是决定cur和rest的，关键可变参数只有status
        """
        if rest == 0:
            return status == 0
        if dp[status] != 0:
            return dp[status] == 1

        ans = False
        for i in range(n):
            if ((status & (1 << i)) != 0) and (cur + matchsticks[i] <= limit):
                if cur + matchsticks[i] == limit:
                    ans = f(limit, status ^ (1 << i), 0, rest - 1)
                else:
                    ans = f(limit, status ^ (1 << i), cur + matchsticks[i], rest)
                if ans:
                    break
        dp[status] = 1 if ans else -1
        return ans
    return f(Sum // k, (1 << n) - 1, 0, k)



def main() -> None:
    matchsticks = list(map(int, sys.stdin.readline().strip().split()))
    if makesquare(matchsticks, 4):
        print('true')
    else:
        print('false')


if __name__ == '__main__':
    main()
