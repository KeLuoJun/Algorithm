# 最接近目标值的子序列和
# 给你一个整数数组 nums 和一个目标值 goal
# 你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal
# 也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal)
# 返回 abs(sum - goal) 可能的 最小值
# 注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
# 数据量描述:
# 1 <= nums.length <= 40
# -10^7 <= nums[i] <= 10^7
# -10^9 <= goal <= 10^9
# 测试链接 : https://leetcode.cn/problems/closest-subsequence-sum/

import sys
from typing import List

def minAbsDifference(nums: List[int], goal: int):
    n = len(nums)
    # 剪枝操作
    max_sum, min_sum = 0, 0
    for num in nums:
        if num > 0:
            max_sum += num
        else:
            min_sum += num
    if max_sum < goal:
        return abs(goal - max_sum)
    if min_sum > goal:
        return abs(goal - min_sum)

    # 原始数组排序，为了后面递归的时候，还能剪枝（常数优化）
    nums.sort()
    l_sum, r_sum = [], []
    def dfs(i, e, s, res):
        if i == e:
            res.append(s)
        else:
            # nums[i.....]这一组，相同的数字有几个
            j = i + 1
            while j < e and nums[j] == nums[i]:
                j += 1
            # nums[ 1 1 1 1 1 2....
			#       i         j
            for k in range(j - i + 1):
                # k = 0个
				# k = 1个
				# k = 2个
                dfs(j, e, s + k * nums[i], res)
    dfs(0, n >> 1, 0, l_sum)
    dfs(n >> 1, n, 0, r_sum)
    l_sum.sort(), r_sum.sort()
    ans = abs(goal)
    j = len(r_sum) - 1
    for i in range(len(l_sum)):
        while j > 0 and abs(goal - l_sum[i] - r_sum[j - 1]) <= abs(goal - l_sum[i] - r_sum[j]):
            j -= 1
        ans = min(ans, abs(goal - l_sum[i] - r_sum[j]))
    return ans
        
def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n, goal = data[0], data[1]
    nums = data[2:2+n]
    print(minAbsDifference(nums, goal))



if __name__ == '__main__':
    main()

