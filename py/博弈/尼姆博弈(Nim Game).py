# 尼姆博弈(Nim Game)
# 一共有n堆石头，两人轮流进行游戏
# 在每个玩家的回合中，玩家需要选择任何一个非空的石头堆，并从这堆石头中移除任意正数的石头数量
# 谁先拿走最后的石头就获胜，返回最终谁会获胜
# 测试链接 : https://www.luogu.com.cn/problem/P2197

import sys

def NimGame(n, arr):
    eor = 0
    for i in range(n):
        eor ^= arr[i]
    return "Yes" if eor else "No"

def main() -> None:
    T = int(sys.stdin.readline().strip())
    for _ in range(T):
        n = int(sys.stdin.readline().strip())
        arr = list(map(int, sys.stdin.readline().strip().split()))
        print(NimGame(n, arr))

if __name__ == '__main__':
    main()
