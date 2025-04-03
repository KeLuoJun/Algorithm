# 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
# 给定一个可能含有重复值的数组 arr
# 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
# 返回所有位置相应的信息。
# 输入描述：
# 第一行输入一个数字 n，表示数组 arr 的长度。
# 以下一行输入 n 个数字，表示数组的值
# 输出描述：
# 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
# 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb

import sys

def solve(arr):
    n = len(arr)
    stack = [0] * n  # 单调栈，严格大压小
    ans = [[0] * 2 for _ in range(n)]
    r = 0
    for i in range(n):
        while r > 0 and arr[stack[r - 1]] >= arr[i]:
            r -= 1
            cur = stack[r]  # cur当前弹出的位置，左边最近且小
            ans[cur][0] = stack[r - 1] if r > 0 else -1
            ans[cur][1] = i
        stack[r] = i
        r += 1

    # 清算阶段
    while r > 0:
        r -= 1
        cur = stack[r]
        ans[cur][0] = stack[r - 1] if r > 0 else -1
        ans[cur][1] = -1

    # 修正阶段(对于数组中存在重复数字)
    # 左侧的答案不需要修正一定是正确的，只有右侧答案需要修正
    # 从右往左修正，n-1位置的右侧答案一定是-1，不需要修正
    for i in range(n - 2, -1, -1):
        if ans[i][1] != -1 and arr[ans[i][1]] == arr[i]:
            ans[i][1] = ans[ans[i][1]][1]
    return ans

def main():
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    ans = solve(arr.copy())
    
    for i in range(n):
        print(ans[i][0], ans[i][1])

if __name__ == '__main__':
    main()
    
