# 逆序对数量(归并分治)
# 给定一个长度为n的数组arr
# 如果 i < j 且 arr[i] > arr[j]
# 那么(i,j)就是一个逆序对
# 求arr中逆序对的数量
# 1 <= n <= 5 * 10^5
# 1 <= arr[i] <= 10^9
# 测试链接 : https://www.luogu.com.cn/problem/P1908

import sys

def f(arr, help, l, r):
    """
    归并分治
	1) 统计i、j来自l~r范围的情况下，逆序对数量
	2) 统计完成后，让arr[l...r]变成有序的
    """
    if l == r:
        return 0
    m = (l + r) // 2
    return f(arr, help, l, m) + f(arr, help, m + 1, r) + merge(arr, help, l, m, r)

def merge(arr, help, l, m, r):
    """
    i来自l.....m
    j来自m+1...r
    统计有多少逆序对
    """
    ans = 0
    i, j, = m, r
    while i >= l:
        while j > m and arr[i] <= arr[j]:
            j -= 1
        ans += j - m  # j - (m + 1) - 1
        i -= 1
    # 左右部分合并，整体变有序，归并排序的过程
    i, a, b, = l, l, m + 1
    while a <= m and b <= r:
        if arr[a] <= arr[b]:
            help[i] = arr[a]
            a += 1
        else:
            help[i] = arr[b]
            b += 1
        i += 1
    while a <= m:
        help[i] = arr[a]
        a += 1
        i += 1
    while b <= r:
        help[i] = arr[b]
        b += 1
        i += 1

    for i in range(l, r + 1):
        arr[i] = help[i]
    return ans
        

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    n = data[ptr]
    ptr += 1
    arr = data[ptr:]
    help = [0] * n
    ans = f(arr, help, 0, n - 1)
    print(ans)


if __name__ == '__main__':
    main()
