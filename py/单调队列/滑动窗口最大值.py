# 滑动窗口最大值（单调队列经典用法模版）
# 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
# 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
# 返回 滑动窗口中的最大值 。
# 测试链接 : https://leetcode.cn/problems/sliding-window-maximum/

import sys

def maxSlidingWindow(nums, k):
    n = len(nums)
    deque = [0] * n
    h = t = 0
    # 先形成长度为k-1的窗口
    for i in range(k - 1):
        # 大 -> 小
        while h < t and nums[deque[t - 1]] <= nums[i]:
            t -= 1
        deque[t] = i
        t += 1
    m = n - k + 1
    ans = [0] * m
    l, r = 0, k - 1
    while l < m:
        # 少一个，要让r位置的数进来
        while h < t and nums[deque[t - 1]] <= nums[r]:
            t -= 1
        deque[t] = r
        t += 1
        ans[l] = nums[deque[h]]  # 收集答案
        if deque[h] == l:  # l位置的数出去
            h += 1
        l += 1
        r += 1
    return ans

def main() -> None:
    n, k = map(int, sys.stdin.readline().split())
    nums = list(map(int, sys.stdin.readline().split()))
    print(maxSlidingWindow(nums, k))


if __name__ == '__main__':
    main()
