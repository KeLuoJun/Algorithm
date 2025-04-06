# 绝对差不超过限制的最长连续子数组
# 给你一个整数数组 nums ，和一个表示限制的整数 limit
# 请你返回最长连续子数组的长度
# 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
# 如果不存在满足条件的子数组，则返回 0
# 测试链接 : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/


import sys
from typing import List
from collections import deque

# 判断如果加入数字number，窗口最大值 - 窗口最小值是否依然 <= limit
# 依然 <= limit，返回true
# 不再 <= limit，返回false
def ok(nums, maxdq, mindq, limit, num):
    maxnum = max(nums[maxdq[0]], num) if maxdq else num
    minnum = min(nums[mindq[0]], num) if mindq else num
    return maxnum - minnum <= limit

# r位置的数字进入窗口，修改窗口内最大值的更新结构、修改窗口内最小值的更新结构
def push(nums, maxdq, mindq, idx):
    while maxdq and nums[maxdq[-1]] <= nums[idx]:
        maxdq.pop()
    maxdq.append(idx)
    while mindq and nums[mindq[-1]] >= nums[idx]:
        mindq.pop()
    mindq.append(idx)

# 窗口要吐出l位置的数了！检查过期！
def pop(nums, maxdq, mindq, idx):
    if maxdq and maxdq[0] == idx:
        maxdq.popleft()
    if mindq and mindq[0] == idx:
        mindq.popleft()

def longestSubarray(nums: List[int], limit: int) -> int:
    n = len(nums)
    # 窗口内最大值的更新结构（单调队列）
    maxdq = deque()
    # 窗口内最小值的更新结构（单调队列）
    mindq = deque()
    ans = 0
    l = r = 0
    while l < n:
        # [l,r)，r永远是没有进入窗口的、下一个数所在的位置  
        while r < n and ok(nums, maxdq, mindq, limit, nums[r]):
            push(nums, maxdq, mindq, r)
            r += 1
        # 从while出来的时候，[l,r)是l开头的子数组能向右延伸的最大范围
        ans = max(ans, r - l)
        pop(nums, maxdq, mindq, l)
        l += 1
    return ans


def main() -> None:
    n , limit = map(int, sys.stdin.readline().strip().split())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    ans = longestSubarray(nums, limit)
    print(ans)

if __name__ == '__main__':
    main()



