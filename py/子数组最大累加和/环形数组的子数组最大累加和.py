# 环形数组的子数组最大累加和
# 给定一个数组nums，长度为n
# nums是一个环形数组，下标0和下标n-1是连在一起的
# 返回环形数组中，子数组最大累加和
# 测试链接 : https://leetcode.cn/problems/maximum-sum-circular-subarray/

import sys

def maxSubarraySumCircular(nums):
    n = len(nums)
    all = maxans = minans = nums[0]
    maxpre = minpre = nums[0]
    for i in range(1, n):
        all += nums[i]
        maxpre = max(maxpre + nums[i], nums[i])
        maxans = max(maxans, maxpre)
        minpre = min(minpre + nums[i], nums[i])
        minans = min(minans, minpre)
    return maxans if all == minans else max(maxans, all - minans)
        

def main() -> None:
    n = int(sys.stdin.readline().strip())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    print(maxSubarraySumCircular(nums))


if __name__ == '__main__':
    main()
