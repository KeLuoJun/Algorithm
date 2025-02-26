# 返回无序数组中累加和为给定值的最长子数组长度
# 给定一个无序数组arr, 其中元素可正、可负、可0
# 给定一个整数aim
# 求arr所有子数组中累加和为aim的最长子数组长度
# 测试链接 : https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5

n, k = map(int, input().split())
nums = list(map(int, input().split()))

# 滑动窗口
def solve_1():
    ans = 0
    sum = 0
    l = 0
    for r in range(n):
        sum += nums[r]
        if sum > k:
            sum -= nums[l]
            l += 1
        if sum == k:
            ans = max(ans, r - l + 1)
    return ans

# 构建前缀信息
def solve_2():
    m = {}
    m[0] = -1
    ans = 0
    perfix_sum = 0
    for i in range(n):
        perfix_sum += nums[i]
        if perfix_sum - k in m:
            ans = max(ans, i - m[perfix_sum - k])
        if perfix_sum not in m:
            m[perfix_sum] = i
    return ans


print(solve_1())
