# 斐波那契博弈(Fibonacci Game + Zeckendorf定理)
# 一共有n枚石子，两位玩家定了如下规则进行游戏：
# 先手后手轮流取石子，先手在第一轮可以取走任意的石子
# 接下来的每一轮当前的玩家最少要取走一个石子，最多取走上一次取的数量的2倍
# 当然，玩家取走的数量必须不大于目前场上剩余的石子数量，双方都以最优策略取石子
# 你也看出来了，根据规律先手一定会获胜，但是先手想知道
# 第一轮自己取走至少几颗石子就可以保证获胜了
# 测试链接 : https://www.luogu.com.cn/problem/P6487

import sys
import bisect

def build():
    global MAXN, f
    f[0] = 1
    f[1] = 2
    size = 1
    while f[size] <= MAXN:
        f[size + 1] = f[size] + f[size - 1]
        size += 1
    
def fibonacciGame(n):
    global f
    ans = -1
    while n != 1 and n != 2:
        find = f[bisect.bisect_left(f, n)]
        if find == n:
            ans = find
            break
        else:
            n -= find
    return ans if ans != -1 else n

def main() -> None:
    build()
    n = int(sys.stdin.readline().strip())
    print(fibonacciGame(n))


if __name__ == '__main__':
    MAXN = 1e15
    MAXM = 101
    f = [0 for _ in range(MAXM)] 
    main()
