# 交错符串
# 给定三个字符串 s1、s2、s3
# 请帮忙验证s3是否由s1和s2交错组成
# 测试链接 : https://leetcode.cn/problems/interleaving-string/

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        n = len(s1)
        m = len(s2)

        if n + m != len(s3):
            return False

        dp = [[False] * (m + 1) for _ in range(n + 1)]
        
        dp[0][0] = True
        # 只有s1时，能否得到s3
        for i in range(1, n + 1):
            dp[i][0] = (dp[i - 1][0] and s1[i - 1] == s3[i - 1])
        # 只有s2时，能否得到s3  
        for j in range(1, m + 1):
            dp[0][j] = (dp[0][j - 1] and s2[j - 1] == s3[j - 1])
        
        for i in range(1, n + 1):
            for j in range(1, m + 1):
                # 当前位置的字符与s3相同，还要看这个字符串之前的字符是否有组成s3的字符 
                dp[i][j] = (s1[i - 1] == s3[i + j - 1] and dp[i - 1][j]) or (s2[j - 1] == s3[i + j - 1] and dp[i][j - 1])
        return dp[-1][-1]
