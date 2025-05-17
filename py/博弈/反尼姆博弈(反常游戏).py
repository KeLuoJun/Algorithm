# 反尼姆博弈(反常游戏)
# 一共有n堆石头，两人轮流进行游戏
# 在每个玩家的回合中，玩家需要选择任何一个非空的石头堆，并从这堆石头中移除任意正数的石头数量
# 谁先拿走最后的石头就失败，返回最终谁会获胜
# 先手获胜，打印John
# 后手获胜，打印Brother
# 测试链接 : https://www.luogu.com.cn/problem/P4279

import sys

def antiNimGame(n, arr):
    eor, s = 0, 0
    for num in arr:
        eor ^= num
        s += num
    if n == s:
        return "Brother" if n % 2 else "John"
    else:
        return "John" if eor else "Brother"

def main() -> None:
    T = int(sys.stdin.readline().strip())
    for _ in range(T):
        n = int(sys.stdin.readline().strip())
        arr = list(map(int, sys.stdin.readline().strip().split()))
        print(antiNimGame(n, arr))


if __name__ == '__main__':
    main()
