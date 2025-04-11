# 环形数组中不能选相邻元素的最大累加和
# 给定一个数组nums，长度为n
# nums是一个环形数组，下标0和下标n-1是连在一起的
# 可以随意选择数字，但是不能选择相邻的数字
# 返回能得到的最大累加和
# 测试链接 : https://leetcode.cn/problems/house-robber-ii/

import sys

def rob(nums):
    n = len(nums)
    # 不环形数组求不能相邻元素的最大累加和
    def best(l, r):
        nonlocal nums
        if l > r:
            return 0
        if l == r:
            return nums[l]
        if l + 1 == r:
            return max(nums[l], nums[r])
        prepre = nums[l]
        pre = max(nums[l], nums[l + 1])
        for i in range(l + 2, r + 1):
            # 1、不要当前数字 pre
            # 2、要当前数字 nums[i] 和 nums[i] + prepre 比较
            cur = max(pre, nums[i] + max(0, prepre))
            prepre = pre
            pre = cur
        return pre
    if n == 1:
        return nums[0]
    # 1、不要0位置的数，则在1到n-1之间选
    # 2、要0位置的数，则在2到n-2之间选（选了0位置的数，则不能选1位置和n-1位置的数）
    return max(best(1, n - 1), nums[0] + best(2, n - 2))


def main() -> None:
    n = int(sys.stdin.readline().strip())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    print(rob(nums))


if __name__ == '__main__':
    main()
