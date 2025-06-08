# HH的项链
# 一共有n个位置，每个位置颜色给定，i位置的颜色是arr[i]
# 一共有m个查询，question[i] = {li, ri}
# 表示第i条查询想查arr[li..ri]范围上一共有多少种不同颜色
# 返回每条查询的答案
# 1 <= n、m、arr[i] <= 10^6
# 1 <= li <= ri <= n
# 测试链接 : https://www.luogu.com.cn/problem/P1972

import sys
from typing import DefaultDict

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    n = data[ptr]
    ptr += 1
    arr = [0] + data[ptr:ptr + n]
    ptr += n
    m = data[ptr]
    ptr += 1
    qs = []
    for i in range(m):
        qs.append((data[ptr], data[ptr + 1], i))
        ptr += 2

    # 定义树状数组
    tree = [0] * (n + 1)
    # 定义树状数组的操作函数
    def lowbit(i):
        return i & (-i)

    def add(i, v):
        while i <= n:
            tree[i] += v
            i += lowbit(i)
    
    def query(i):
        ans = 0
        while i > 0:
            ans += tree[i]
            i -= lowbit(i)
        return ans
    def sum_(l, r):
        return query(r) - query(l - 1)

    # 计算过程
    ans = [0] * m
    mp = DefaultDict(int)  # 存放每一种颜色最右侧出现的位置
    # 根据每个查询的右边界进行排序
    qs_sorted = sorted(qs, key=lambda x: x[1])
    s = 1  # 当前遍历到的最右查询位置
    for q in range(m):
        r = qs_sorted[q][1]
        while s <= r:
            color = arr[s]
            if mp[color] != 0:
                add(mp[color], -1)
            add(s, 1)
            mp[color] = s   # 更新颜色最右侧出现的位置
            s += 1
        l = qs_sorted[q][0]
        i = qs_sorted[q][2]
        ans[i] = sum_(l, r)
    
    print("\n".join(map(str, ans)))


if __name__ == '__main__':
    main()

