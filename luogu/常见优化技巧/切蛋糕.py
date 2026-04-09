# https://www.luogu.com.cn/problem/P1714

import sys
from collections import deque

def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    p_arr = [0] + list(map(int, sys.stdin.readline().strip().split()))
    for i in range(1, n + 1):
        p_arr[i] += p_arr[i - 1]
    
    ans = -float('inf')
    q = deque()
    q.append(0)

    for i in range(1, n + 1):
        while q and q[0] < i - m:
            q.popleft()
        
        if q:
            ans = max(ans, p_arr[i] - p_arr[q[0]])

        while q and p_arr[q[-1]] >= p_arr[i]:
            q.pop()
        q.append(i)
    print(ans)


if __name__ == '__main__':
    main()

