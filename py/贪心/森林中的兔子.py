# 森林中的兔子
# 森林中有未知数量的兔子
# 你问兔子们一个问题: "还有多少只兔子与你颜色相同?"
# 你将答案收集到了一个数组answers中
# 你可能没有收集到所有兔子的回答，可能只是一部分兔子的回答
# 其中answers[i]是第i只兔子的答案
# 所有兔子都不会说错，返回森林中兔子的最少数量
# 测试链接 : https://leetcode.cn/problems/rabbits-in-forest/

import sys
from typing import List

def numRabbits(arr: List[int]):
    n = len(arr)
    arr.sort()
    ans = 0
    i, j = 0, 1
    while i < n:
        x = arr[i]
        while j < n and x == arr[j]:
            j += 1
        ans += (j - i + x) // (x + 1) * (x + 1)
        i = j
        j += 1
    return ans


def main() -> None:
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    print(numRabbits(arr))


if __name__ == '__main__':
    main()
