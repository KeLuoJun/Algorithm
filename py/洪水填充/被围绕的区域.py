# 被围绕的区域
# 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域
# 并将这些区域里所有的 'O' 用 'X' 填充。
# 测试链接 : https://leetcode.cn/problems/surrounded-regions/

import sys

def solve(board):
    n, m = len(board), len(board[0])
    def dfs(board, n, m, i, j):
        if i < 0 or i == n or j < 0 or j == m or board[i][j] == 'X':
            return
        MOVE = [-1, 0, 1, 0, -1]
        board[i][j] = 'F'
        for k in range(4):
            dfs(board, n, m, i + MOVE[k], j + MOVE[k + 1])
    for j in range(m):
        if board[0][j] == 'O':
            dfs(board, n, m, 0, j)
        if board[n - 1][j] == 'O':
            dfs(board, n, m, n - 1, j)
    for i in range(1, n - 1):
        if board[i][0] == 'O':
            dfs(board, n, m, i, 0)
        if board[i][m - 1] == 'O':
            dfs(board, n, m, i, m - 1)
    for i in range(n):
        for j in range(m):
            if board[i][j] == 'O':
                board[i][j] = 'X'
            if board[i][j] == 'F':
                board[i][j] = 'O'
    return board

def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    board = [list(map(str, sys.stdin.readline().strip().split())) for _ in range(n)]
    print(solve(board))

if __name__ == '__main__':
    main()
