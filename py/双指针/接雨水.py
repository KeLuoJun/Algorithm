# 接雨水
# 给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
# 测试链接 : https://leetcode.cn/problems/trapping-rain-water/

import sys

def solve(height):
    n = len(height)
    l, r = 1, n - 2
    ans = 0
    lmax, rmax = height[0], height[n-1]
    while l <= r:
        if lmax <= rmax:
            ans += max(0, lmax - height[l])
            lmax = max(lmax, height[l])
            l += 1
        else:
            ans += max(0, rmax - height[r])
            rmax = max(rmax, height[r])
            r -= 1
    return ans


def main():
    n = int(sys.stdin.readline().strip())
    height = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(height))

if __name__ == '__main__':
    main()

    
    