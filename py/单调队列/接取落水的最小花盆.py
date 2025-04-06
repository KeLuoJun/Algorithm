# 接取落水的最小花盆
# 老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x 轴的位置
# 每滴水以每秒1个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置
# 使得从被花盆接着的第 1 滴水开始，到被花盆接着的最后 1 滴水结束，之间的时间差至少为 D
# 我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住
# 给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W
# 测试链接 : https://www.luogu.com.cn/problem/P2698

import sys

def solve(arr, d):
    # arr[0...n-1][2]: x(0), 高度(1)
	# 所有水滴根据x排序，谁小谁在前
    n = len(arr)
    maxh, maxt, minh, mint = 0, 0, 0, 0
    maxdq, mindq = [0] * n, [0] * n

    def ok():
        nonlocal maxh, maxt, minh, mint
        max_num = arr[maxdq[maxh]][1] if maxh < maxt else 0
        min_num = arr[mindq[minh]][1] if minh < mint else 0
        return max_num - min_num >= d

    def push(i):
        nonlocal maxh, maxt, minh, mint
        while maxh < maxt and arr[maxdq[maxt - 1]][1] <= arr[i][1]:
            maxt -= 1
        maxdq[maxt] = i
        maxt += 1
        while minh < mint and arr[mindq[mint - 1]][1] >= arr[i][1]:
            mint -= 1
        mindq[mint] = i
        mint += 1

    def pop(i):
        nonlocal maxh, maxt, minh, mint
        if maxh < maxt and maxdq[maxh] == i:
            maxh += 1
        if minh < mint and mindq[minh] == i:
            minh += 1

    arr.sort(key=lambda x: (x[0], x[1]))
    
    ans = float('inf')
    r = 0
    for l in range(n):
        # [l,r) : 水滴的编号
		# l : 当前花盘的左边界，arr[l][0]
        while not ok() and r < n:
            push(r)
            r += 1
        # 可能题目根本就不可能满足 
        if ok():
            ans = min(ans, arr[r - 1][0] - arr[l][0])
        pop(l)
    return ans

def main():
    n, d = map(int, sys.stdin.readline().strip().split())
    arr = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(n)]
    print(solve(arr, d))

if __name__ == '__main__':
    main()
