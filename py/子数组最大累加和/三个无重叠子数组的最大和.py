# 三个无重叠子数组的最大和
# 给你一个整数数组 nums 和一个整数 k
# 找出三个长度为 k 、互不重叠、且全部数字和（3 * k 项）最大的子数组
# 并返回这三个子数组
# 以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置
# 如果有多个结果，返回字典序最小的一个
# 测试链接 : https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/

class Solution:
    def maxSumOfThreeSubarrays(self, nums: list[int], k: int) -> list[int]:
        # sums[i] : 以i开头并且长度为k的子数组的累加和
        n = len(nums)
        sums = [0] * (n)
        l, r, sum = 0, 0, 0
        for r in range(n):
            sum += nums[r]
            if r - l + 1 == k:
                sums[l] = sum
                sum -= nums[l]
                l += 1
        # prefix[i] :
	    # 0~i范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
        prefix = [0] * n
        # l为当前k区间的起始点，r为当前k区间的末点
	    # （因为 sums 是以 l 为起点且长度为k的和）
        # example: k = 3
        # prefix[0]: 0..0  不够k个
        # prefix[1]: 0..1  不够k个
        # prefix[2]: 0..2  够k个，也是直接填0
        # prefix[3]: prefix[i-1]  当前情况，来pk
        # .....l-1, l, ... r-1, r
        l, r = 1, k
        while r < n:
            if sums[l] > sums[prefix[r - 1]]:
                prefix[r] = l
            else:
                prefix[r] = prefix[r - 1]
            r += 1
            l += 1
        
        # suffix[i] :
	    # i~n-1范围上所有长度为k的子数组中，拥有最大累加和的子数组，是以什么位置开头的
        # .....l,l+1,....
        suffix = [0] * n
        suffix[n - k] = n - k
        for l in range(n - k - 1, -1, -1):
            if sums[l] >= sums[suffix[l + 1]]:
                # 注意>=，为了同样最大累加和的情况下，最小的字典序
                suffix[l] = l
            else:
                suffix[l] = suffix[l + 1]
        
        ans, a, b, c = 0, 0, 0, 0
        #    a         b          c 
        # 0...i-1    i...j    j+1...n-1
        #   左     中(长度为k)     右
        i, j = k,  2 * k - 1
        sum = 0
        while j < n - k:
            # 0.....i-1     i.....j   j+1.....n-1
		    # 最好开头p      i开头     最好开头s
            p = prefix[i - 1]
            s = suffix[j + 1]
            sum = sums[p] + sums[i] + sums[s]
            if ans < sum:
                # 注意>，为了同样最大累加和的情况下，最小的字典序
                ans = sum
                a, b, c = p, i, s
            i += 1
            j += 1
        return a, b, c


        
