# 子数组的最小值之和
# 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
# 由于答案可能很大，答案对 1000000007 取模
# 测试链接 : https://leetcode.cn/problems/sum-of-subarray-minimums/


import sys
def solve(arr):
    MOD = 1e9 + 7
    n = len(arr)
    stack = [0] * n
    r, ans = 0, 0
    for i in range(n):
        # 相等的时候也压入，后面会修复当前漏算的的区间
        while r > 0 and arr[stack[r - 1]] >= arr[i]:
            r -= 1
            cur = stack[r]
            left = stack[r - 1] if r > 0 else -1
            # left left+1 ... cur ... i-1 i
            # 区间left+1到i+1之间的最小值一定为arr[cur]
            ans = (ans + (i - cur) * (cur - left) * arr[cur]) % MOD
        stack[r] = i
        r += 1

    while r > 0:
        r -= 1
        cur = stack[r]
        left = stack[r - 1] if r > 0 else -1
        ans = (ans + (n - cur) * (cur - left) * arr[cur]) % MOD
    return int(ans)
            
def main():
    n = int(sys.stdin.readline().strip())
    arr = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(arr.copy()))

if __name__ == '__main__':
    main()
               

