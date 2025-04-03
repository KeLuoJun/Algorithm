# 每日温度
# 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
# 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
# 如果气温在这之后都不会升高，请在该位置用 0 来代替。
# 测试链接 : https://leetcode.cn/problems/daily-temperatures/

import sys

def solve(temperatures):
    n = len(temperatures)
    stacks = [0] * n  # 严格小压大
    r = 0
    ans = [0] * n
    for i in range(n):
        while r > 0 and temperatures[i] > temperatures[stacks[r - 1]]:
            r -= 1
            cur = stacks[r]
            ans[cur] = i - cur
        stacks[r] = i
        r += 1

    return ans
          

def main() -> None:
    n = int(sys.stdin.readline().strip())
    temperatures = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(temperatures.copy()))
    

if __name__ == '__main__':
    main()


