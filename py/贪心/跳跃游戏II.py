# 跳跃游戏II
# 给定一个长度为n的整数数组nums
# 你初始在0下标，nums[i]表示你可以从i下标往右跳的最大距离
# 比如，nums[0] = 3
# 表示你可以从0下标去往：1下标、2下标、3下标
# 你达到i下标后，可以根据nums[i]的值继续往右跳
# 返回你到达n-1下标的最少跳跃次数
# 测试用例可以保证一定能到达
# 测试链接 : https://leetcode.cn/problems/jump-game-ii/

class Solution:
    def jump(self, nums: list[int]) -> int:
        n = len(nums)
        cur = 0  # 当前步以内，最右到哪
        next = 0  # 如果再一步，(当前步+1)以内，最右到哪
        ans = 0  # 一共需要跳几步
        for i in range(n):
            # 来到i下标
			# cur包括了i所在的位置，不用付出额外步数
			# cur没有包括i所在的位置，需要付出额外步数
            if cur < i:
                ans += 1
                cur = next
            next = max(next, i + nums[i])
        return ans
        
