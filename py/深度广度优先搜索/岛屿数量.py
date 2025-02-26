def dfs(grid, i, j):
    if i < 0 or i >= len(grid) or j < 0 or \
        j >= len(grid[0]) or grid[i][j] == 0:
        return 
    grid[i][j] = 0
    dfs(grid, i + 1, j)
    dfs(grid, i - 1, j)
    dfs(grid, i, j + 1)
    dfs(grid, i, j - 1)

def main() -> None:
    rows, cols = map(int, input("请输入矩阵的行数和列数: ").split())
    grid = [[0] * cols for _ in range(rows)]
    print("请输入矩阵元素0/1: ")
    for i in range(rows):
        grid[i] = list(map(int, input().split()))
    print(grid)

    islands = 0
    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                dfs(grid, i, j)
                islands += 1
    print("岛屿数量: ", islands)
    

if __name__ == '__main__':
    main()

