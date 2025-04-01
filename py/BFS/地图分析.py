# 地图分析
# 你现在手里有一份大小为 n x n 的 网格 grid
# 上面的每个 单元格 都用 0 和 1 标记好了其中 0 代表海洋，1 代表陆地。
# 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的
# 并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
# 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：
# (x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
# 测试链接 : https://leetcode.cn/problems/as-far-from-land-as-possible/





import sys
MAXM = MAXN = 101
MOVE = [-1, 0, 1, 0, -1]
def bfs(grid, m, n):
    l = r = 0
    queue = [[0 for _ in range(2)] for _ in range(MAXM * MAXN)]
    visited = [[False for _ in range(MAXN)] for _ in range(MAXM)]
    seas = 0
    for i in range(m):
        for j in range(n):
            if grid[i][j] == 1:
                visited[i][j] = True
                queue[r][0] = i
                queue[r][1] = j
                r += 1
            else:
                seas += 1
    
    if seas == 0 or seas == m * n:
        return -1
    
    level = 0
    while l < r:
        level += 1
        size = r - l
        for k in range(size):
            x, y = queue[l][0], queue[l][1]
            l += 1
            for i in range(4):
                nx, ny = x + MOVE[i], y + MOVE[i + 1]
                if 0 <= nx < m and 0 <= ny < n and not visited[nx][ny]:
                    visited[nx][ny] = True
                    queue[r][0] = nx
                    queue[r][1] = ny
                    r += 1
    return level - 1


def main() -> None:
    m, n = map(int, input().strip().split())
    grid = []
    for _ in range(m):
        grid.append(list(map(int, input().strip().split())))
    print(bfs(grid, m, n))
    

if __name__ == '__main__':
    main()



