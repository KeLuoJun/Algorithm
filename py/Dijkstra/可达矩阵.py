# 可达矩阵
import numpy as np

class Grahp:
    def __init__(self, vertices, edges):
        self.v = vertices
        self.edges = edges
        self.adj_matrix = np.zeros((vertices, vertices), dtype=int)


    def get_adj_matrix(self, weight=1):
        for u, v in self.edges:
            self.adj_matrix[u][v] = weight
        return self.adj_matrix
    
    def get_reachability_matrix(self):
        reach_matrix = np.array(self.adj_matrix, copy=True)
        # reach_matrix[reach_matrix > 0] = 1

        for k in range(self.v):
            for i in range(self.v):
                for j in range(self.v):
                    reach_matrix[i][j] = reach_matrix[i][j] or \
                        (reach_matrix[i][k] and reach_matrix[k][j])
        return reach_matrix  # 可达矩阵
    
    def count_paths_of_length(self, m):
        result = np.linalg.matrix_power(self.adj_matrix, m)

        total_paths = np.sum(result)  # 长度为 m 的通路总数

        cycles = np.trace(result)  # 回路总数

        return total_paths, cycles

def main():
    v, e, m = map(int, input("请输入图的信息\n[点数] [边数] [通道长度]\n").split())
    edges = [[0] * 2 for _ in range(e)]
    print("[起点] [终点]")
    for i in range(e):
        edges[i] = list(map(int, input().split()))
    g = Grahp(v, edges)
    print("邻接矩阵：\n", g.get_adj_matrix())
    print("可达矩阵：\n", g.get_reachability_matrix())
    total_paths, cycles = g.count_paths_of_length(m)
    print("长度为 m 的通路总数：", total_paths)
    print("回路总数：", cycles)


if __name__ == '__main__':
    main()