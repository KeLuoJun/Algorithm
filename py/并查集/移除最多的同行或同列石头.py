# 移除最多的同行或同列石头
# n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头
# 如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头
# 给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置
# 返回 可以移除的石子 的最大数量。
# 测试链接 : https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/

import sys
from collections import defaultdict

sets = None
row_first = defaultdict()
col_first = defaultdict()
father = []


def build(n):
    global father, sets
    father = [i for i in range(n)]
    sets = n

def find(i):
    global father
    if i != father[i]:
        father[i] = find(father[i])
    return father[i]

def union(x, y):
    global father, sets
    fx = find(x)
    fy = find(y)
    if fx != fy:
        father[fx] = fy
        sets -= 1
        
def removeStones(stones):
    global sets, row_first, col_first, father
    n = len(stones)
    build(n)
    for i in range(n):
        row, col = stones[i][0], stones[i][1]
        if row in row_first:
            union(i, row_first[row])
        else:
            row_first[row] = i
        if col in col_first:
            union(i, col_first[col])
        else:
            col_first[col] = i
    return n - sets
    

def main() -> None:
    n = int(sys.stdin.readline().strip())
    stones = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    print(removeStones(stones))


if __name__ == '__main__':
    main()