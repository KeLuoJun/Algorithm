# https://www.luogu.com.cn/problem/P1469

import sys
def main() -> None:
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))

    ans = 0
    for a in arr:
        ans ^= a
    
    print(ans)


if __name__ == '__main__':
    main()
