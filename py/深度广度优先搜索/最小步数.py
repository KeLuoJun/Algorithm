from typing import List
import sys
import queue

def find_shortest_path_dfs(grid: List[List[int]]):
    if not grid or not grid[0]:
        return -1
    
    rows, cols = len(grid), len(grid[0])
    if grid[0][0] == -1 or grid[rows - 1][cols - 1] == -1:
        return -1
    
    def is_valid(x, y):
        return 0 <= x < rows and 0 <= y < cols and grid[x][y] != -1
    
    min_steps = [sys.maxsize] 
    visited = set()

    def dfs(x, y, steps):
        if steps >= min_steps[0]:
            return
        
        if x == rows - 1 and y == cols - 1:
            min_steps[0] = min(min_steps[0], steps)
            return
        
        directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if is_valid(nx, ny) and (nx, ny) not in visited:
                visited.add((nx, ny))
                dfs(nx, ny, steps + 1)
                visited.remove((nx, ny))

    visited.add((0, 0))
    dfs(0, 0, 0)

    return min_steps[0] if min_steps[0] != sys.maxsize else -1



def find_shortest_path_bfs(grid: List[List[int]]):
    if not grid or not grid[0]:
        return -1
    
    rows, cols = len(grid), len(grid[0])
    if grid[0][0] == -1 or grid[rows - 1][cols - 1] == -1:
        return -1
    
    def is_valid(x, y):
        return 0 <= x < rows and 0 <= y < cols and grid[x][y] != -1
    

    def bfs():
        q = queue.Queue()
        q.put((0, 0, 0))
        visited = set((0, 0))

        while q:
            x, y, steps = q.get()

            if x == rows - 1 and y == cols - 1:
                return steps
            
            directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]
            for dx, dy in directions:
                nx, ny = x + dx, y + dy
                if is_valid(nx, ny) and (nx, ny) not in visited:
                    visited.add((nx, ny))
                    q.put((nx, ny, steps + 1))
        return -1

    result = bfs()

    return result


def main() -> None:
    rows, cols = map(int, input("请输入矩阵的行数和列数: ").split())
    grid = [[0] * cols for _ in range(rows)]
    print("请输入矩阵元素0/1: ")
    for i in range(rows):
        grid[i] = list(map(int, input().split()))
    print("最小步数: ", find_shortest_path_bfs(grid))

if __name__ == '__main__':
    main()

