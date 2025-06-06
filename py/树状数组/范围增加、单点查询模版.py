# 树状数组范围增加、单点查询模版
# 测试链接 : https://www.luogu.com.cn/problem/P3368

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

def main():
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    n = data[ptr]
    ptr += 1
    m = data[ptr]
    ptr += 1
    o_arr = data[ptr:ptr+n]
    ptr += n

    # 原始数组的信息，维护在树状数组中
    # 注意下标一定从1开始，而不是0
    tree = [0] * (n + 2)  # 树状数组大小为 n+2

    # 初始化树状数组（差分）
    for i in range(1, n+1):
        add(tree, n, i, o_arr[i-1])
        add(tree, n, i+1, -o_arr[i-1])

    # 处理 m 次操作
    for _ in range(m):
        op = data[ptr]
        ptr += 1
        if op == 1:
            l = data[ptr]
            ptr += 1
            r = data[ptr]
            ptr += 1
            v = data[ptr]
            ptr += 1
            add(tree, n, l, v)
            add(tree, n, r + 1, -v)
        elif op == 2:
            index = data[ptr]
            ptr += 1
            print(query(tree, index))


if __name__ == '__main__':
    main()


