# 有依赖的背包(模版)
# 物品分为两大类：主件和附件
# 主件的购买没有限制，钱够就可以；附件的购买有限制，该附件所归属的主件先购买，才能购买这个附件
# 例如，若想买打印机或扫描仪这样的附件，必须先购买电脑这个主件
# 以下是一些主件及其附件的展示：
# 电脑：打印机，扫描仪 | 书柜：图书 | 书桌：台灯，文具 | 工作椅：无附件
# 每个主件最多有2个附件，并且附件不会再有附件，主件购买后，怎么去选择归属附件完全随意，钱够就可以
# 所有的物品编号都在1~m之间，每个物品有三个信息：价格v、重要度p、归属q
# 价格就是花费，价格 * 重要度 就是收益，归属就是该商品是依附于哪个编号的主件
# 比如一件商品信息为[300,2,6]，花费300，收益600，该商品是6号主件商品的附件
# 再比如一件商品信息[100,4,0]，花费100，收益400，该商品自身是主件(q==0)
# 给定m件商品的信息，给定总钱数n，返回在不违反购买规则的情况下最大的收益
# 测试链接 : https://www.luogu.com.cn/problem/P1064
# 测试链接 : https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4


def solution_1():
    dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
    # p : 上次展开的主商品编号  很关键！！！！！！！ 
    p = 0
    for i in range(1, m + 1):
        if king[i]:
            # dp[i][j] : 0...i范围上，只关心主商品，并且进行展开
			#            花费不超过j的情况下，获得的最大收益
            for j in range(0, n + 1):
                # 可能性1：不考虑当前商品
                dp[i][j] = dp[p][j]
                # 可能性2：考虑当前商品，但不考虑附属商品
                if j - cost[i] >= 0:
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i]] + val[i])
                fan1 = flower[i][0] if fans[i] >= 1 else -1
                fan2 = flower[i][1] if fans[i] >= 2 else -1
                # 可能性3：主 + 附1
                if fan1 != -1 and j - cost[i] - cost[fan1] >= 0:
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1]] + val[i] + val[fan1])
                # 可能性4：主 + 附2
                if fan2 != -1 and j - cost[i] - cost[fan2] >= 0:
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan2]] + val[i] + val[fan2])
                # 可能性5：主 + 附1 + 附2
                if fan1 != -1 and fan2 != -1 and j - cost[i] - cost[fan1] - cost[fan2] >= 0:
                    dp[i][j] = max(dp[i][j], dp[p][j - cost[i] - cost[fan1] - cost[fan2]] + val[i] + val[fan1] + val[fan2])
            p = i
    return dp[m][n]



def solution_2():
    dp = [0] * (m + 1)
    for i in range(1, m + 1):
        if king[i]:
            for j in range(n, -1, -1):
                if j - cost[i] >= 0:
                    dp[j] = max(dp[j], dp[j - cost[i]] + val[i])
                fan1 = flower[i][0] if fans[i] >= 1 else -1
                fan2 = flower[i][1] if fans[i] >= 2 else -1
                if fan1 != -1 and j - cost[fan1] >= 0:
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan1]] + val[i] + val[fan1])
                if fan2 != -1 and j - cost[fan2] >= 0:
                    dp[j] = max(dp[j], dp[j - cost[i] - cost[fan2]] + val[i] + val[fan2])
                if fan1 != -1 and fan2 != -1 and j - cost[fan1] - cost[fan2] >= 0:
                    dp[j] = max(dp[j], dp[j - cost[fan1] - cost[fan2] - cost[i]] + val[fan1] + val[fan2] + val[i])
    return dp[n]

m, n = list(map(int, input().split()))

val = [0 for _ in range(m + 1)]
cost = [0 for _ in range(m + 1)]
king = [False for _ in range(m + 1)] # 当前物品是否为主件，是为True， 否为False
fans = [0 for _ in range(m + 1)] # 主件所附属物品的数量
flower = [[0 for _ in range(2)] for _ in range(m + 1)] # 主件所附属物品的编号

for i in range(1, m + 1):
    v, p, q = list(map(int, input().strip()))
    val[i] = v * p
    cost[i] = v
    king[i] = (q == 0)
    if (q != 0):
        fans[q] += 1
        flower[q][fans[q]] = i
print(solution_1())
print(solution_2())

