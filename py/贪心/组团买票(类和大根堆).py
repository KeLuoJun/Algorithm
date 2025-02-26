# 组团买票
# 景区里一共有m个项目，景区的第i个项目有如下两个参数：
# game[i] = { Ki, Bi }，Ki、Bi一定是正数
# Ki代表折扣系数，Bi代表票价
# 举个例子 : Ki = 2, Bi = 10
# 如果只有1个人买票，单张门票的价格为 : Bi - Ki * 1 = 8
# 所以这1个人游玩该项目要花8元
# 如果有2个人买票，单张门票的价格为 : Bi - Ki * 2 = 6
# 所以这2个人游玩该项目要花6 * 2 = 12元
# 如果有5个人买票，单张门票的价格为 : Bi - Ki * 5 = 0
# 所以这5个人游玩该项目要花5 * 0 = 0元
# 如果有更多人买票，都认为花0元(因为让项目倒贴钱实在是太操蛋了)
# 于是可以认为，如果有x个人买票，单张门票的价格为 : Bi - Ki * x
# x个人游玩这个项目的总花费是 : max { x * (Bi - Ki * x), 0 }
# 单位一共有n个人，每个人最多可以选1个项目来游玩，也可以不选任何项目
# 所有员工将在明晚提交选择，然后由你去按照上面的规则，统一花钱购票
# 你想知道自己需要准备多少钱，就可以应付所有可能的情况，返回这个最保险的钱数
# 数据量描述 : 
# 1 <= M、N、Ki、Bi <= 10^5
# 来自真实大厂笔试，没有在线测试，对数器验证

import random
import heapq
from tqdm import tqdm


# 暴力方法
# 为了验证
# 每个人做出所有可能的选择
# 时间复杂度O((m+1)的n次方)
def f(i, n, m, games, cnts):
    if i == n:
        ans = 0
        for j in range(m):
            ans += max(0, (games[j][1] - cnts[j] * games[j][0]) * cnts[j])
        return ans
    else:
        ans = f(i + 1, n, m, games, cnts)  # 不选
        for j in range(m):
            cnts[j] += 1
            ans = max(ans, f(i + 1, n, m, games, cnts))
            cnts[j] -= 1
        return ans

def solve_1(n, m, games):
    # 每个项目去的人数
    cnts = [0] * m
    return f(0, n, m, games, cnts)




class Game:
    def __init__(self, k, b):
        self.k = k  # 折扣系数
        self.b = b  # 票价
        self.people = 0  # 该项目之前的人数
    # 如果再来一人，这个项目得到多少钱
    def earn(self):
        # bi - (people + 1) * ki : 当前的人，门票原价减少了，当前的门票价格  
        # people * ki : 当前人的到来，之前的所有人，门票价格都再减去ki  
        return self.b - self.k * (self.people + 1) - self.people * self.k
    
    def __lt__(self, other):
        return self.earn() < other.earn()

def solve_2(n, m, games):
    # 哪个项目，再来一人挣得最多  
    # 大根堆
    heap = []
    for i in range(m):
        game = Game(games[i][0], games[i][1])
        heapq.heappush(heap, (-game.earn(), game))
    ans = 0
    for i in range(n):
        # 一个个的人，依次送到当前最挣钱的项目里去
        if heap[0][1].earn() < 0:
            break
        cur = heapq.heappop(heap)[1]
        ans += cur.earn()
        cur.people += 1
        heapq.heappush(heap, (-cur.earn(), cur))
    return ans




if __name__ == '__main__':
    # 思路：
    # 将最保险的钱数问题转换为公园最挣钱问题
    print("测试开始")
    for _ in tqdm(range(2000)):
        n, m = random.randint(1, 6), random.randint(1, 6)
        games = []
        for i in range(m):
            game = []
            for j in range(2):
                game.append(random.randint(1, 5))
            games.append(game)

        if solve_2(n, m, games) != solve_1(n, m, games):
            print("出错了！")
            break
    print("测试结束")

