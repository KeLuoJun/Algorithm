# 我能赢吗
# 给定两个整数n和m
# 两个玩家可以轮流从公共整数池中抽取从1到n的整数（不放回）
# 抽取的整数会累加起来（两个玩家都算）
# 谁在自己的回合让累加和 >= m，谁获胜
# 若先出手的玩家能稳赢则返回true，否则返回false
# 假设两位玩家游戏时都绝顶聪明，可以全盘为自己打算
# 测试链接 : https://leetcode.cn/problems/can-i-win/


import sys
from typing import List

def canIWin(maxChoosableInteger: int, desiredTotal: int) -> bool:
    if desiredTotal == 0:
        return True
    if (maxChoosableInteger * (maxChoosableInteger + 1) // 2) < desiredTotal:
        # 如果1~n数字全加起来
        # 累加和和是n * (n+1) / 2，都小于m
        # 那么不会有赢家，也就意味着先手不会获胜
        return False
    # dp[status] == 0 代表没算过
    # dp[status] == 1 算过，答案是true
    # dp[status] == -1 算过，答案是false
    dp = [0] * (1 << (maxChoosableInteger + 1))
    
    def f(status, rest):
        """
        如果1~7范围的数字都能选，那么status的状态为：
        1 1 1 1 1 1 1 1
        7 6 5 4 3 2 1 0
        0位弃而不用
        如果1~7范围的数字，4、2已经选了不能再选，那么status的状态为：
        1 1 1 0 1 0 1 1
        7 6 5 4 3 2 1 0
        0位弃而不用
        f的含义 :
        数字范围1~n，当前的先手，面对status给定的数字状态
        在累加和还剩rest的情况下
        返回当前的先手能不能赢，能赢返回true，不能赢返回false
        """
        if rest <= 0:  # rest是对手拿完后的剩余目标值
            return False
        if dp[status] != 0:
            return dp[status] == 1
        # rest > 0
        ans = False
        for i in range(1, maxChoosableInteger + 1):
            # 考察所有数字，但是不能选择之前选了的数字
            if ((status & (1 << i)) != 0 and not f(status ^ (1 << i), rest - i)):
                ans = True
                break
        dp[status] = 1 if ans else -1
        return ans
    return f((1 << (maxChoosableInteger + 1)) - 1, desiredTotal)


def main() -> None:
    maxChoosableInteger, desiredTotal = map(int, sys.stdin.readline().strip().split())
    if canIWin(maxChoosableInteger, desiredTotal):
        print('true')
    else:
        print('false')


if __name__ == '__main__':
    main()
