# Kruskal算法模版（洛谷）
# 静态空间实现
# 测试链接 : https://www.luogu.com.cn/problem/P3366
# 并查集 + 对边的权值排序 

class Kruskal:
    def __init__(self, n, m, edges):
        self.n = n
        self.m = m
        self._father = [0] * (self.n + 1)
        self._edges = edges

    @property
    def ans(self):
        self._edges.sort(key=lambda x: x[2])
        self.build()
        result = 0
        edge_cnt = 0
        for edge in self._edges:
            if self.union(edge[0], edge[1]):
                result += edge[2]
                edge_cnt += 1
        if edge_cnt == self.n - 1:
            return result
        else:
            return "此图不连通！"
    def build(self) -> None:
        for i in range(1, self.n + 1):
            self._father[i] = i

    def find(self, i) -> int:
        if i != self._father[i]:
            self._father[i] = self.find(self._father[i])
        return self._father[i]

    def union(self, x, y) -> bool:
        fx = self.find(x)
        fy = self.find(y)
        if fx != fy:
            self._father[fx] = fy
            return True
        else:
            return False

def main():
    n, m = map(int, input("请输入图的信息\n[点数] [边数]\n").split())
    edges = [[0] * 3 for _ in range(m)]
    print("[起点] [终点] [权重]")
    for i in range(m):
        edges[i] = list(map(int, input().split()))
    k = Kruskal(n, m, edges)
    print(k.ans)
    
if __name__ == '__main__':
    main()