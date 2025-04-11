# 编辑距离
# 给你两个单词 word1 和 word2
# 请返回将 word1 转换成 word2 所使用的最少代价
# 你可以对一个单词进行如下三种操作：
# 插入一个字符，代价a
# 删除一个字符，代价b
# 替换一个字符，代价c
# 测试链接 : https://leetcode.cn/problems/edit-distance/

import sys

# 原初尝试版
# a : str1中插入1个字符的代价
# b : str1中删除1个字符的代价
# c : str1中改变1个字符的代价
# 返回从str1转化成str2的最低代价
def editDistance1(s1, s2, a, b, c):
    n,m = len(s1), len(s2)
    # dp[i][j] :
	# s1[前缀长度为i]想变成s2[前缀长度为j]，至少付出多少代价
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for i in range(1, n + 1):
        dp[i][0] = i * b
    for j in range(1, m + 1):
        dp[0][j] = j * a
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            p1 = float('inf')
            if s1[i - 1] == s2[j - 1]:
                p1 = dp[i - 1][j - 1]
            p2 = float('inf')
            if s1[i - 1] != s2[j - 1]:
                p2 = dp[i - 1][j - 1] + c
            p3 = dp[i][j - 1] + a
            p4 = dp[i - 1][j] + b
            dp[i][j] = min([p1, p2, p3, p4])
    return dp[n][m]

def minDistance(word1, word2):
    return editDistance1(word1, word2, 1, 1, 1)

def main() -> None:
    word1 = sys.stdin.readline().strip()
    word2 = sys.stdin.readline().strip()
    print(minDistance(word1, word2))

if __name__ == '__main__':
    main()
