# 最长递增子序列和最长不下降子序列
# 给定一个整数数组nums
# 找到其中最长严格递增子序列长度、最长不下降子序列长度
# 测试链接 : https://leetcode.cn/problems/longest-increasing-subsequence/

import sys
from typing import List
import bisect

def lengthgthOfLIS1(nums: List[int]):
    """
    普通解法的动态规划
	时间复杂度O(n^2)，数组稍大就会超时
    """
    n = len(nums)
    dp = [1] * n
    ans = 0
    for i in range(n):
        for j in range(i):
            if nums[i] > nums[j]:
                dp[i] = max(dp[i], dp[j] + 1)
        ans = max(ans, dp[i])
    return ans   

def lengthgthOfLIS2(nums: List[int]):
    """
    最优解
	时间复杂度O(n * logn)
    """
    n = len(nums)
    # len表示ends数组目前的有效区长度
	# ends[0...len-1]是有效区，有效区内的数字一定严格升序
    length = 0
    ends = [0] * n

    # 定义二分查找函数
    def bs1(length, num):
        """
        "最长递增子序列"使用如下二分搜索 :
        ends[0...length-1]是严格升序的，找到>=num的最左位置
        如果不存在返回-1
        """
        l, r = 0, length - 1
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if ends[mid] >= num:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans
    def bs2(length, num):
        """
        如果求最长不下降子序列，那么使用如下的二分搜索 :
        ends[0...length-1]是不降序的
        在其中找到>num的最左位置，如果不存在返回-1
        如果求最长不下降子序列，就在lengthgthOfLIS中把bs1方法换成bs2方法
        """
        l, r = 0, length - 1
        ans = -1
        while l <= r:
            mid = (l + r) // 2
            if ends[mid] > num:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans

    for num in nums:
        find = bs1(length, num)
        if find == -1:
            ends[length] = num
            length += 1
        else:
            ends[find] = num
    return length

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    arr = data[1:1+n]
    print(lengthgthOfLIS2(arr))


if __name__ == '__main__':
    main()
