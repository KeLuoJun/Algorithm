# 预测赢家
# 给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏
# 玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手
# 开始时，两个玩家的初始分值都是 0
# 每一回合，玩家从数组的任意一端取一个数字
# 取到的数字将会从数组中移除，数组长度减1
# 玩家选中的数字将会加到他的得分上
# 当数组中没有剩余数字可取时游戏结束
# 如果玩家 1 能成为赢家，返回 true
# 如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true
# 你可以假设每个玩家的玩法都会使他的分数最大化
# 测试链接 : https://leetcode.cn/problems/predict-the-winner/

import sys
from typing import List

def predictTheWinner1(nums: List[int]) -> bool:
    """记忆化搜索"""
    n = len(nums)
    Sum = sum(nums)
    dp = [[-1] * n for _ in range(n)]

    def f(l, r):
        """
        nums[l...r]范围上的数字进行游戏，轮到玩家1
	    返回玩家1最终能获得多少分数，玩家1和玩家2都绝顶聪明  
        """
        if dp[l][r] != -1:
            return dp[l][r]
        ans = 0
        if l == r:
            return nums[l]
        elif l == r - 1:
            return max(nums[l], nums[r])
        else:  # l....r 不只两个数
            # 可能性1 ：玩家1拿走nums[l] l+1...r -> 玩家2拿走nums[l + 1] or nums[r]
            # 玩家2一定会给玩家1一个最差的结果
            p1 = nums[l] + min(f(l + 2, r), f(l + 1, r - 1))
            # 可能性2 ：玩家1拿走nums[r] l...r-1 -> 玩家2拿走nums[r - 1] or nums[l]
            p2 = nums[r] + min(f(l + 1, r - 1), f(l, r - 2))
            ans = max(p1, p2)
        dp[l][r] = ans
        return ans
    
    first = f(0, n - 1)
    second = Sum - first
    return first >= second


def predictTheWinner2(nums: List[int]) -> bool:
    """严格位置依赖的动态规划"""
    Sum = sum(nums)
    n = len(nums)
    dp = [[0] * n for _ in range(n)]
    for i in range(n - 1):
        dp[i][i] = nums[i]
        dp[i][i + 1] = max(nums[i], nums[i + 1])
    dp[n - 1][n - 1] = nums[n - 1]
    for l in range(n - 3, -1, -1):
        for r in range(l + 2, n):
            dp[l][r] = max(
                nums[l] + min(dp[l + 2][r], dp[l + 1][r - 1]),
                nums[r] + min(dp[l + 1][r - 1], dp[l][r - 2])
            )
    first = dp[0][n - 1]
    second = Sum - first
    return first >= second


def main() -> None:
    nums = list(map(int, sys.stdin.readline().strip().split()))
    if predictTheWinner2(nums):
        print('true')
    else:
        print('false')


if __name__ == '__main__':
    main()
