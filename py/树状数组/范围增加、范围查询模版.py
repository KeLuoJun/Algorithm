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

    info1 = [0] * (n + 2)
    info2 = [0] * (n + 2)
    for i in range(1, n + 1):
        pass
        


if __name__ == '__main__':
    main()
