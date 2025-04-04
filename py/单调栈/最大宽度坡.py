# 最大宽度坡
# 给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]
# 这样的坡的宽度为 j - i，找出 A 中的坡的最大宽度，如果不存在，返回 0
# 测试链接 : https://leetcode.cn/problems/maximum-width-ramp/
import sys

def solve(nums):
    n = len(nums)
    stack = [0] * n   # 严格小压大，相等不入栈
    r, ans = 1, 0
    for i in range(1, n):
        if nums[stack[r - 1]] > nums[i]:
            stack[r] = i
            r += 1
    for j in range(n - 1, -1, -1):
        while r > 0 and nums[stack[r - 1]] <= nums[j]:
            r -= 1
            ans = max(ans, j - stack[r])
    return ans    

def main():
    n = int(sys.stdin.readline().strip())
    nums = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(nums))

if __name__ == '__main__':
    main()
