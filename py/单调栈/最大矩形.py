# 最大矩形
# 给定一个仅包含 0 和 1 、大小为 rows * cols 的二维二进制矩阵
# 找出只包含 1 的最大矩形，并返回其面积
# 测试链接：https://leetcode.cn/problems/maximal-rectangle/

import sys

def maximalRectangle(matrix):
    m, n = len(matrix), len(matrix[0])
    height = [0] * n
    ans = 0
    for i in range(m):
        # 来到i行，长方形一定要以i行做底！
        # 如果遇到0，高度就归零（不能接续上面的高度）
		# 加工高度数组(压缩数组)
        for j in range(n):
            height[j] = height[j] + 1 if matrix[i][j] != '0' else 0
        ans = max(ans, largestRectangleArea(height.copy()))
    return ans


def largestRectangleArea(height):
    n = len(height)
    stack = [0] * n
    r, ans = 0, 0
    for i in range(n):
        while r > 0 and height[stack[r - 1]] >= height[i]:
            r -= 1
            cur = stack[r]
            left = stack[r - 1] if r > 0 else -1
            ans = max(ans, height[cur] * (i - left - 1))
        stack[r] = i
        r += 1
    while r > 0:
        r -= 1
        cur = stack[r]
        left = stack[r - 1] if r > 0 else -1
        ans = max(ans, height[cur] * (n - left - 1))
    return ans
        
        

def main():
    m, n = map(int, sys.stdin.readline().strip().split())
    matrix = []
    for _ in range(m):
        matrix.append(list(map(int, sys.stdin.readline().strip().split())))
    print(maximalRectangle(matrix))

if __name__ == '__main__':
    main()