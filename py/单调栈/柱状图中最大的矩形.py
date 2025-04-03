# 柱状图中最大的矩形
# 给定 n 个非负整数，用来表示柱状图中各个柱子的高度
# 每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积
# 测试链接：https://leetcode.cn/problems/largest-rectangle-in-histogram

import sys

def largestRectangleArea(heights):
    n = len(heights)
    stack = [0] * n
    r, ans = 0, 0
    for i in range(n):
        while r > 0 and heights[stack[r - 1]] >= heights[i]:
            r -= 1
            cur = stack[r]
            left = stack[r - 1] if r > 0 else -1
            ans = max(ans, (i - left - 1) * heights[cur])
        stack[r] = i
        r += 1
    while r > 0:
        r -= 1
        cur = stack[r]
        left = stack[r - 1] if r > 0 else -1
        ans = max(ans, (n - left - 1) * heights[cur])
    return ans

def main():
    n = int(sys.stdin.readline().strip())
    heights = list(map(int, sys.stdin.readline().strip().split()))
    print(largestRectangleArea(heights.copy()))

if __name__ == '__main__':
    main()