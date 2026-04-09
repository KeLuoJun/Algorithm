# 使数组K递增的最少操作次数
# 给你一个下标从0开始包含n个正整数的数组arr，和一个正整数k
# 如果对于每个满足 k <= i <= n-1 的下标 i
# 都有 arr[i-k] <= arr[i] ，那么称 arr 是K递增的
# 每一次操作中，你可以选择一个下标i并将arr[i]改成任意正整数
# 请你返回对于给定的 k ，使数组变成K递增的最少操作次数
# 测试链接 : https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/

import sys
from typing import List

def kIncreasing(arr: List[int], k):
    n = len(arr)
    ans = 0
    for i in range(k):
        nums = []
        for j in range(i, n, k):
            nums.append(arr[j])
        size = len(nums)
        ans += size - lengthOfNoDecreasing(nums)
    return ans

def lengthOfNoDecreasing(nums: List[int]):
    def bs(length, num):
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
    n = len(nums)

    length = 0
    ends = [0] * n
    for num in nums:
        find = bs(length, num)
        if find == -1:
            ends[length] = num
            length += 1
        else:
            ends[find] = num
    return length


def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n, k = data[0], data[1]
    arr = data[2:]
    print(kIncreasing(arr, k))


if __name__ == '__main__':
    main()
