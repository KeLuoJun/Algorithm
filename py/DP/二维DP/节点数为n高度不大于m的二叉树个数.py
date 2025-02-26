# 节点数为n高度不大于m的二叉树个数
# 现在有n个节点，计算出有多少个不同结构的二叉树
# 满足节点个数为n且树的高度不超过m的方案
# 因为答案很大，所以答案需要模上1000000007后输出
# 测试链接 : https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea


def solution(n, m):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    for j in range(m + 1):
        dp[0][j] = 1

    for i in range(1, n + 1):
        for j in range(1, m + 1):
            for k in range(i):
                # 一共i个节点，头节点已经占用了1个名额
			    # 如果左树占用k个，那么右树就占用i-k-1个
                dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][j - 1] % MOD) % MOD
    return dp[-1][-1]

MOD = 1000000007
n, m = map(int, input().split())
print(solution(n, m))