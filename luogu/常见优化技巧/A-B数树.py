# https://www.luogu.com.cn/problem/P1102


import sys
from collections import defaultdict

def solve(n, c, arr):
    d = defaultdict(int)
    for i in range(n):
        d[arr[i]] += 1

    ans = 0
    for k, v in d.items():
        if (k + c) in d:
            ans += v * d[k + c]
    return ans

def main() -> None:
    n, c = map(int, sys.stdin.readline().strip().split())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(n, c, arr))
    


if __name__ == '__main__':
    main()
