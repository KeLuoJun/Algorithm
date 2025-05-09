# 使数组相似的最少操作次数
# 给你两个正整数数组 nums 和 target ，两个数组长度相等
# 在一次操作中，你可以选择两个 不同 的下标 i 和 j
# 其中 0 <= i, j < nums.length ，并且：
# 令 nums[i] = nums[i] + 2 且
# 令 nums[j] = nums[j] - 2
# 如果两个数组中每个元素出现的频率相等，我们称两个数组是 相似 的
# 请你返回将 nums 变得与 target 相似的最少操作次数
# 测试数据保证nums一定能变得与target相似
# 测试链接 : https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar/

from typing import List
import sys

def makeSimilar(nums: List[int], target: List[int]):
    n = len(nums)
    def split(arr: List[int], n):
        oddsize = 0
        for i in range(n):
            if arr[i] & 1:
                arr[i], arr[oddsize] = arr[oddsize], arr[i]
                oddsize += 1
        return oddsize
    oddsize = split(nums, n)
    split(target, n)
    nums[:oddsize] = sorted(nums[:oddsize])
    nums[oddsize:] = sorted(nums[oddsize:])
    target[:oddsize] = sorted(target[:oddsize])
    target[oddsize:] = sorted(target[oddsize:])
    ans = 0
    for i in range(n):
        ans += abs(nums[i] - target[i])
    return ans // 4


def main() -> None:
    n = int(sys.stdin.readline().strip())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    target = list(map(int, sys.stdin.readline().strip().split()))
    print(makeSimilar(nums, target))


if __name__ == '__main__':
    main()

        