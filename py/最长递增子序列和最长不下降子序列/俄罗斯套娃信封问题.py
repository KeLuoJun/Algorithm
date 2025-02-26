# 俄罗斯套娃信封问题
# 给你一个二维整数数组envelopes ，其中envelopes[i]=[wi, hi]
# 表示第 i 个信封的宽度和高度
# 当另一个信封的宽度和高度都比这个信封大的时候
# 这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
# 请计算 最多能有多少个信封能组成一组“俄罗斯套娃”信封
# 即可以把一个信封放到另一个信封里面，注意不允许旋转信封
# 测试链接 : https://leetcode.cn/problems/russian-doll-envelopes/

class Solution:
    def maxEnvelopes(self, envelopes: list[list[int]]) -> int:
        # 根据宽度由小到大排，若相等则按高度由大到小排
        envelopes.sort(key=lambda x: (x[0], -x[1])) 
        # 求排序后的高度的最长递增子序列即为答案
        ends = [0] * (len(envelopes))
        length = 0
        for _, h in envelopes:  # 提只取排序后的高度
            find = self.bs_1(ends, length, h)
            if find == -1:
                ends[length] = h
                length += 1
            else:
                ends[find] = h
        return length
    # 求最长递增子序列使用的二分查法
    def bs_1(self, ends, length, target):
        l, r, ans = 0, length - 1, -1
        while l <= r:
            mid = (l + r) // 2
            if ends[mid] >= target:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans


    # 如果求最长不下降子序列，那么使用如下的二分搜索 :
    # ends[0...len-1]是不降序的
    # 在其中找到>num的最左位置，如果不存在返回-1
    # 如果求最长不下降子序列，就在lengthOfLIS中把bs1方法换成bs2方法
    def bs_2(self, ends, length, targrt):
        l, r, ans = 0, length - 1, -1
        while l <= r:
            mid = (l + r) // 2
            if ends[mid] > targrt:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
        return ans        