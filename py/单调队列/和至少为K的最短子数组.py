# 和至少为K的最短子数组
# 给定一个数组arr，其中的值有可能正、负、0
# 给定一个正数k
# 返回累加和>=k的所有子数组中，最短的子数组长度
# 测试链接 : https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

import sys
from collections import deque

def shortestSubarray(nums, k):
    n = len(nums)
    pre_sum = [0] * (n + 1)
    for i in range(n):
        pre_sum[i + 1] = pre_sum[i] + nums[i]
    
    dq = deque()
    ans = sys.maxsize
    for i in range(n + 1):
        while dq and pre_sum[i] <= pre_sum[dq[-1]]:
            dq.pop()
        while dq and pre_sum[i] - pre_sum[dq[0]] >= k:
            ans = min(ans, i - dq.popleft())
        dq.append(i)
    return ans if ans != sys.maxsize else -1


def main() -> None:
    n, k = map(int, sys.stdin.readline().strip().split())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    print(shortestSubarray(nums, k))


if __name__ == '__main__':
    main()
