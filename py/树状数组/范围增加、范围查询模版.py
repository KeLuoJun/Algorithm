# 树状数组范围增加、范围查询模版
# 测试链接 : https://www.luogu.com.cn/problem/P3372

import sys

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    ptr = 0
    n = data[ptr]
    ptr += 1
    m = data[ptr]
    ptr += 1

    arr = data[ptr:ptr + n]
    ptr += n

    # 维护原始数组的差分信息：Di
    info1 = [0] * (n + 2)
    # 维护原始数组的差分加工信息：(i - 1) * Di
    info2 = [0] * (n + 2)

    # 定义树状数组操作函数
    def lowbit(i):
        return i & (-i)
    def add_sub(tree, i, v):
        while i <= n:
            tree[i] += v
            i += lowbit(i)
    def add(l, r, v):
        add_sub(info1, l, v)
        add_sub(info1, r + 1, -v)
        add_sub(info2, l, (l - 1) * v)
        add_sub(info2, r + 1, r * (-v))
    def sum_(tree, i):
        ans = 0
        while i > 0:
            ans += tree[i]
            i -= lowbit(i)
        return ans
    def query(l, r):
        # 查询 l-r 区间的累加和
        # 推导后的公式：sum(l, r) = sum(r) - sum(l - 1) = 
        # (sum_(info1, r) * r - sum_(info2, r)) - (sum_(info1, l - 1) * (l - 1) - sum_(info2, l - 1))
        return sum_(info1, r) * r - sum_(info2, r) - sum_(info1, l - 1) * (l - 1) + sum_(info2, l - 1)

    # 构建初始化树状数组
    for i in range(n):
        add(i+1, i+1, arr[i])

    # 操作循环
    for _ in range(m):
        if data[ptr] == 1:
            l, r, v = data[ptr + 1], data[ptr + 2], data[ptr + 3]
            ptr += 4
            add(l, r, v)
        elif data[ptr] == 2:
            l, r = data[ptr + 1], data[ptr + 2]
            ptr += 3
            print(query(l, r))


if __name__ == '__main__':
    main()
