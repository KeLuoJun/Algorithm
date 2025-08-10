# Python算法细节注意点

## Runtime Error
1. 防止除0 或 模0
2. 注意数组越界(边界先判断再访问)



# Python常见库的使用
collection
heapq
itertools
math
random
statistics




# 单调栈

## 算法适应
求左右两边比自己大/小且最近的元素

## 步骤
1. 确定单调栈的栈顶栈底的大小顺序（是否严格），以及栈中存储的元素（数值、下标、元组等）
2. 进栈要严格按照规定的规则，不满足的先出栈/不进栈等操作，并计算结果，直到满足规则后的入栈

- 难点：相等的是否是否进栈，后续相等的值能否修正前面相等的值所漏算或错误的结果

```python
# 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
# 给定一个可能含有重复值的数组 arr
# 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
# 返回所有位置相应的信息。
# 输入描述：
# 第一行输入一个数字 n，表示数组 arr 的长度。
# 以下一行输入 n 个数字，表示数组的值
# 输出描述：
# 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。

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
```


# 单调队列


```python
# 滑动窗口最大值（单调队列经典用法模版）
# 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
# 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
# 返回 滑动窗口中的最大值 。

import sys
def maxSlidingWindow(nums, k):
    n = len(nums)
    deque = [0] * n
    h = t = 0
    # 先形成长度为k-1的窗口
    for i in range(k - 1):
        # 大 -> 小
        while h < t and nums[deque[t - 1]] <= nums[i]:
            t -= 1
        deque[t] = i
        t += 1
    m = n - k + 1
    ans = [0] * m
    l, r = 0, k - 1
    while l < m:
        # 少一个，要让r位置的数进来
        while h < t and nums[deque[t - 1]] <= nums[r]:
            t -= 1
        deque[t] = r
        t += 1
        ans[l] = nums[deque[h]]  # 收集答案
        if deque[h] == l:  # l位置的数出去
            h += 1
        l += 1
        r += 1
    return ans

def main() -> None:
    n, k = map(int, sys.stdin.readline().split())
    nums = list(map(int, sys.stdin.readline().split()))
    print(maxSlidingWindow(nums, k))

if __name__ == '__main__':
    main()
```

# 并查集

```python
# 情侣牵手
# n对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手
# 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的ID
# 情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)
# 返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起
# 每次交换可选择任意两人，让他们站起来交换座位

class Solution:
    def minSwapsCouples(self, row: list[int]) -> int:
        self.m = len(row) // 2
        self.build()
        for i in range(0, len(row), 2):
            self.unions(row[i] // 2, row[i + 1] // 2)
        return self.m - self.sets

    def build(self):
        self.father = [x for x in range(0, self.m)]
        self.sets = self.m

    def find(self, i):
        if self.father[i] != i:
            self.father[i] = self.find(self.father[i])
        return self.father[i]
    def unions(self, x, y):
        fx = self.find(x)
        fy = self.find(y)
        if (fx != fy):
            self.father[fx] = fy
            self.sets -= 1
```

# 博弈问题



# 树状数组
- 动态实时查询和修改数组

## 
