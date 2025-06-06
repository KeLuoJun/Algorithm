# 树状数组单点增加、范围查询模版
# 测试链接 : https://www.luogu.com.cn/problem/P3374

import sys

def lowbit(i):
    """
    得到i最右侧的1的状态
    其他位都是0
    """
    return i & (-i)

def add(tree, n, i, v):
    """ 在树状数组中，将i位置的值加上v """
    while i <= n:
        tree[i] += v
        i += lowbit(i)

def query(tree, i):
    """ 返回1~i范围累加和 """
    ans = 0
    while i > 0:
        ans += tree[i]
        i -= lowbit(i)
    return ans

def range_query(tree, l, r):
    return query(tree, r) - query(tree, l - 1)

def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    o_arr = list(map(int, sys.stdin.readline().strip().split()))
    # 原始数组的信息，维护在树状数组中
    # 注意下标一定从1开始，而不是0
    tree = [0] * (n + 1)
    # 构建树状数组
    for i in range(1, n + 1):
        add(tree, n, i, o_arr[i - 1])
    for _ in range(m):
        arr = list(map(int, sys.stdin.readline().strip().split()))
        if arr[0] == 1:
            add(tree, n, arr[1], arr[2])
        elif arr[0] == 2:
            print(range_query(tree, arr[1], arr[2]))


if __name__ == '__main__':
    main()

