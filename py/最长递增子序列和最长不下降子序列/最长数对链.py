# 最长数对链
# 给你一个由n个数对组成的数对数组pairs
# 其中 pairs[i] = [lefti, righti] 且 lefti < righti
# 现在，我们定义一种 跟随 关系，当且仅当 b < c 时
# 数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面
# 我们用这种形式来构造 数对链
# 找出并返回能够形成的最长数对链的长度
# 测试链接 : https://leetcode.cn/problems/maximum-length-of-pair-chain/

import sys
from typing import List

def findLongestChain(pairs: List[List[int]]):
    n = len(pairs)
    # 数对根据开始位置排序，从小到大
	# 结束位置无所谓！
    pairs.sort(key=lambda x: x[0])

    def bs(length, num):
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

    # 结尾的数值
    ends = [0] * n
    length = 0
    for pair in pairs:
        find = bs(length, pair[0])
        if find == -1:
            ends[length] = pair[1]
            length += 1
        else:
            ends[find] = min(ends[find], pair[1])
    return length


# 最优解：利用贪心
def findLongestChain2(pairs: List[List[int]]):
    pairs.sort(key=lambda x: x[1])
    pre, ans = -sys.maxsize, 0
    for pair in pairs:
        if pre < pair[0]:
            pre = pair[1]
            ans += 1
    return ans



def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    pairs = [[data[i], data[i + 1]] for i in range(1, 2 * n, 2)]
    print(findLongestChain(pairs))


if __name__ == '__main__':
    main()
