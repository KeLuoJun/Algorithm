# HH的项链
# 一共有n个位置，每个位置颜色给定，i位置的颜色是arr[i]
# 一共有m个查询，question[i] = {li, ri}
# 表示第i条查询想查arr[li..ri]范围上一共有多少种不同颜色
# 返回每条查询的答案
# 1 <= n、m、arr[i] <= 10^6
# 1 <= li <= ri <= n
# 测试链接 : https://www.luogu.com.cn/problem/P1972

import sys

def compute(arr):
    n = len(arr)
    

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    n = data[ptr]
    ptr += 1
    arr = data[ptr:ptr + n]
    ptr += n
    m = data[ptr]
    ptr += 1
    for _ in range(m):
        l, r = data[ptr], data[ptr + 1]
        ptr += 2


if __name__ == '__main__':
    main()

