# 盛最多水的容器
# 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
# 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
# 返回容器可以储存的最大水量
# 说明：你不能倾斜容器
# 测试链接 : https://leetcode.cn/problems/container-with-most-water/
import sys

def solve(height):
    n = len(height)
    ans = 0
    l, r = 0, n - 1
    while l <= r:
        ans = max(ans, min(height[l], height[r]) * (r - l))
        if height[l] <= height[r]:
            l += 1
        else:
            r -= 1
    return ans


def main():
    n = int(sys.stdin.readline().strip())
    height = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(height))

if __name__ == '__main__':
    main()
    