# 一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
# 表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
# m个操作做完之后，统计1~n范围上所有数字的最大值和异或和
# 测试链接 : https://www.luogu.com.cn/problem/P4231

import sys

def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    diff = [0] * (n + 3)
    def build():
        nonlocal diff
        for i in range(1, len(diff)):
            diff[i] += diff[i - 1]
        for i in range(1, len(diff)):
            diff[i] += diff[i - 1]
    def set(l, r, s, e, d):
        nonlocal diff
        diff[l] += s
        diff[l + 1] += d - s
        diff[r + 1] -= d + e
        diff[r + 2] += e


    for _ in range(m):
        l, r, s, e = map(int, sys.stdin.readline().strip().split())
        set(l, r, s, e, (e - s) // (r - l))
    build()
    maxans, xor = 0, 0
    for i in range(1, n + 1):
        maxans = max(maxans, diff[i])
        xor ^= diff[i]
    print(f'{xor} {maxans}')



if __name__ == '__main__':
    main()
