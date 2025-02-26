# 救生艇
# 给定数组 people
# people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
# 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
# 返回 承载所有人所需的最小船数
# 测试链接 : https://leetcode.cn/problems/boats-to-save-people/

class Solution:
    def numRescueBoats(self, people: list[int], limit: int) -> int:
        n = len(people)
        people.sort()
        l, r = 0, n - 1
        ans = 0
        while l <= r:
            sum = people[l] + people[r] if l  < r else people[r]
            if sum <= limit:
                r -= 1
                l += 1
            else:
                r -=1
            ans += 1
        return ans
        