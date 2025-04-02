# 二维接雨水
# 给你一个 m * n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度
# 请计算图中形状最多能接多少体积的雨水。
# 测试链接 : https://leetcode.cn/problems/trapping-rain-water-ii/

import sys
import heapq

def bfs(height):
    MOVE = [-1, 0, 1, 0, -1]
    m, n = len(height), len(height[0])
    heap = []
    visited = [[False] * n for _ in range(m)]
    for i in range(m):
        for j in range(n):
            if i == 0 or i == m - 1 or j == 0 or j == n - 1:
                # 边界
                heapq.heappush(heap, [height[i][j], i, j])
                visited[i][j] = True

    ans = 0
    while heap:
        w, r, c = heapq.heappop(heap)
        ans += w - height[r][c]
        for i in range(4):
            nr, nc = r + MOVE[i], c + MOVE[i + 1]
            if 0 <= nr < m and 0 <= nc < n and not visited[nr][nc]:
                heapq.heappush(heap, [max(height[nr][nc], w), nr, nc])
                visited[nr][nc] = True
    return ans
        


def main():
    m, n = map(int, sys.stdin.readline().strip().split())
    height = []
    for _ in range(m):
        height.append(list(map(int, sys.stdin.readline().strip().split())))
    print(bfs(height))
    
        

if __name__ == '__main__':
    main()

