# https://www.luogu.com.cn/problem/P2032


import sys
from collections import deque

def solve(n, k, arr):
    q = deque()
    ans = []
    for i in range(k):
        while q and arr[q[-1]] <= arr[i]:
            q.pop()
        q.append(i)
    ans.append(str(arr[q[0]]))
    for i in range(k, n):
        while q and arr[q[-1]] <= arr[i]:
            q.pop()
        q.append(i)
        if q[0] <= i - k:
            q.popleft()
        ans.append(str(arr[q[0]]))
    return ans

def main() -> None:
    n, k = map(int, sys.stdin.readline().strip().split())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    print('\n'.join(solve(n, k, arr)))


if __name__ == '__main__':
    main()
