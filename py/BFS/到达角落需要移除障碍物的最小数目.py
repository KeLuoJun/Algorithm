# 到达角落需要移除障碍物的最小数目
# 给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n
# 每个单元格都是两个值之一：
# 0 表示一个 空 单元格，
# 1 表示一个可以移除的 障碍物
# 你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。
# 现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) 
# 返回需要移除的障碍物的最小数目
# 测试链接 : https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/



import sys
from collections import deque

def bfs_01(grid):
    MOVE = [-1, 0, 1, 0, -1]
    m = len(grid)
    n = len(grid[0])
    queue = deque()
    distance = [[float('inf')] * n for _ in range(m)]

    queue.appendleft([0, 0])
    distance[0][0] = 0
    while queue:
        x, y = queue.popleft()
        if x == m - 1 and y == n - 1:
            return distance[x][y]
        for i in range(4):
            nx, ny = x + MOVE[i], y + MOVE[i + 1]
            if 0 <= nx < m and 0 <= ny < n \
               and distance[nx][ny] > distance[x][y] + grid[nx][ny]:
                distance[nx][ny] = distance[x][y] + grid[nx][ny]
                if grid[nx][ny] == 0:
                    queue.appendleft([nx, ny])
                else:
                    queue.append([nx, ny])
    return -1
    


def main():
    m, n = map(int, input().strip().split())
    grid = []
    for _ in range(m):
        grid.append(list(map(int, input().strip().split())))
    print(bfs_01(grid))
    
if __name__ == '__main__':
    main()

