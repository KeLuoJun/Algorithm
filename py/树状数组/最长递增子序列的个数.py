# 最长递增子序列的个数
# 给定一个未排序的整数数组nums，返回最长递增子序列的个数
# 测试链接 : https://leetcode.cn/problems/number-of-longest-increasing-subsequence/

import sys

def findNumberOfLIS(nums):
    n = len(nums)
    sorted_nums = sorted(nums)
    unique_sorted = []
    m = 0
    for num in sorted_nums:
        if not unique_sorted or num != unique_sorted[-1]:
            unique_sorted.append(num)
            m += 1
    
    rank_map = {}
    for idx, num in enumerate(unique_sorted, start=1):
        rank_map[num] = idx
    rank_nums = [rank_map[num] for num in nums]

    # 查询结尾数值 <=i 的最长递增子序列长度，复制给max_len
    # 查询结尾数值 <=i 的最长递增子序列的个数，复制给max_lencnt
    max_len, max_lencnt = 0, 0

    # 维护信息：以数值i结尾的最长递增子序列，长度多少
    # 维护的信息以树状数组组织
    tree_maxlen = [0] * (n + 1)
    # 维护信息：以数值i结尾的最长递增子序列，数量多少
    tree_maxlencnt = [0] * (n + 1)

    # 定义树状数组操作函数
    def lowbit(i):
        return i & (-i)

    def add(i, len, cnt):
        while i <= n:
            if tree_maxlen[i] == len:
                tree_maxlencnt[i] += cnt
            elif tree_maxlen[i] < len:
                tree_maxlen[i] = len
                tree_maxlencnt[i] = cnt
            i += lowbit(i)
    
    def query(i):
        nonlocal max_len, max_lencnt
        max_len = max_lencnt = 0
        while i > 0:
            if max_len == tree_maxlen[i]:
                max_lencnt += tree_maxlencnt[i]
            elif max_len < tree_maxlen[i]:
                max_len = tree_maxlen[i]
                max_lencnt = tree_maxlencnt[i]
            i -= lowbit(i)

    for num in rank_nums:
        query(num - 1)
        if max_len == 0:
            # 如果查出数值<=i-1结尾的最长递增子序列长度为0
            # 那么说明，以值num结尾的最长递增子序列长度就是1，计数增加1
            add(num, 1, 1)
        else:
            # 如果查出数值<=i-1结尾的最长递增子序列长度不为0
            # 那么说明，以值num结尾的最长递增子序列长度就是max_len + 1,计数增加max_lencnt
            add(num, max_len + 1, max_lencnt)
    query(m)
    return max_lencnt



def main() -> None:
    nums = list(map(int, sys.stdin.readline().strip().split()))
    print(findNumberOfLIS(nums))


if __name__ == '__main__':
    main()
