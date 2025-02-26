# 返回无序数组中正数和负数个数相等的最长子数组长度
# 给定一个无序数组arr，其中元素可正、可负、可0
# 求arr所有子数组中正数与负数个数相等的最长子数组的长度
# 测试链接 : https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb

n = int(input())
nums = list(map(int, input().split()))
nums = [1 if num > 0 else -1 if num < 0 else 0 for num in nums]
perfix_sum=0
m = {}
m[0] = -1
ans = 0
for i in range(n):
    perfix_sum += nums[i]
    if perfix_sum in m:
        ans = max(ans, i - m[perfix_sum])
    else:
        m[perfix_sum] = i
print(ans)