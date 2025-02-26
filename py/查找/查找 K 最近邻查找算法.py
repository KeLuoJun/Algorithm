# 查找 K 最近邻查找算法
from collections import defaultdict, namedtuple
import heapq
import math

Point = namedtuple("Point", ['x', 'y'])

class GridKNN:
    def __init__(self, points, grid_size=1.0):
        self.grid = defaultdict(list)
        self.grid_size = grid_size
        self._build_grid(points)
    
    def _build_grid(self, points):
        """将点集合分配到网格中"""
        for point in points:
            grid_x = int(point.x / self.grid_size)
            grid_y = int(point.y / self.grid_size)
            self.grid[(grid_x, grid_y)].append(point)
        
    def _distance(self, p1, p2):
        """计算两点之间的欧几里得距离"""
        return math.sqrt((p1.x - p2.x)**2 + (p1.y - p2.y)**2)

    def find_k_nearest(self, target, k):
        """查找最近的 k 个点"""

        grid_x = int(target.x / self.grid_size)
        grid_y = int(target.y / self.grid_size)
    
        # 小根堆存储最近的k个点
        nearest = []  # 距离的负值，点的坐标
        searched_cells = set()

        # 搜索的网格范围，从近到远扩展
        radius = 0
        while len(nearest) < k or -nearest[0][0] < self.grid_size * (radius - 1):
            # 搜索当前半径的所有网络
            for i in range(-radius, radius + 1):
                for j in range(-radius, radius + 1):
                # 只搜索边界网络
                    if abs(i) == radius or abs(j) == radius:
                        current_cell = (grid_x + i, grid_y + j)
                    
                        if current_cell in searched_cells:
                            continue
                    
                        searched_cells.add(current_cell)

                        # 处理当前网格中的所有点
                        for point in self.grid[current_cell]:
                            dist = self._distance(point, target)
                            if len(nearest) < k:
                                heapq.heappush(nearest, (-dist, point))
                            elif -dist > nearest[0][0]:
                                heapq.heapreplace(nearest, (-dist, point))
            radius += 1
        
        return [(point, -dist) for dist, point in sorted(nearest)]
    
def main():
    points = [
        Point(2, 3), Point(5, 4), Point(9, 6),
        Point(4, 7), Point(8, 1), Point(7, 2)
    ]
    
    print("点的坐标为:\n", points)

    knn = GridKNN(points)
    target = Point(6, 5)
    k = 3

    nearest = knn.find_k_nearest(target, k)
    print(f'目标点: {target}')
    print(f'{k}个临近点:')
    for point, dist in nearest:
        print(f'{point}  距离: {dist:.2f}')

if __name__=='__main__':
    main()