# 小红拿到了一个长度为 10^100的数组，初始所有元素都是 0。现在小红准备进行 q 次操作，每一次：
# 小红查询一个区间，如果区间内所有元素都是 0，那么将区间修改为首项为 1、公差为 1 的等差数列；否则不进行任何操作。
# 小红希望你在每次操作后都输出当前数组的元素种类数，即统计数组中不同元素的个数。
# 测试链接：https://ac.nowcoder.com/acm/contest/111159/D

import sys
from math import gcd
input = sys.stdin.readline

def lowbit(x):
    return x & -x

def query(x):
    res = 0
    while x:
        res += s[x]
        x -= lowbit(x)
    return res

def update(x, a):
    while x <= n:
        s[x] += a
        x += lowbit(x)

q = int(input())

cur = 1
maxx = 0
n = int(3e5 + 5)
s = [0] * (int(3e5 + 5))

for i in range(q):
    l, r = map(int, input().split())
    t = query(r) - query(l - 1)
    if t == 0:
       num = r - l + 1
       if num > maxx:
           cur += num - maxx
           maxx = num
       update(l, 1)
       update(r, 1)
    print(cur)
