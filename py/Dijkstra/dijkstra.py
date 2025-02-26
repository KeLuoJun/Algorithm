# Description: Dijkstra算法的实现
# Attention: 图的节点编号从1开始
# O(m * logm) m为边数
import heapq

class Dijkstra:
    def __init__(self, n, edge_cnt, start, edges):
        self.n = n
        self.start = start
        self.edge_cnt = edge_cnt
        self.edges = edges
        self.map = [[] for _ in range(n + 1)]
        self.distances = [float("inf")] * (n + 1)
        self.visited = [False] * (n + 1)

    def mapping(self):
        for u, v, w in self.edges:
            self.map[u].append((v, w))

    @property
    def ans(self):
        self.mapping()
        self.distances[self.start] = 0
        heap = []
        heapq.heappush(heap, (0, self.start))
        while heap:
            u = heapq.heappop(heap)[1]
            if self.visited[u]:
                continue
            self.visited[u] = True
            for edge in self.map[u]:
                v, w = edge
                if (not self.visited[v]) and self.distances[v] > self.distances[u] + w:
                    self.distances[v] = self.distances[u] + w
                    heapq.heappush(heap, (self.distances[v], v))
        for i in range(1, self.n + 1):
            if self.distances[i] == float('inf'):
                return "此图不连通！"
        return self.distances[1:]        



def main():
    n, edge_cnt, start = map(int, input("请输入图的信息\n[点数] [边数] [开始节点]\n").split())
    edges = []
    print("[起点] [终点] [权重]")
    for _ in range(edge_cnt):
        edges.append(list(map(int, input().split())))
    d = Dijkstra(n, edge_cnt, start, edges)
    print(d.ans)
    
if __name__ == '__main__':
    main()

