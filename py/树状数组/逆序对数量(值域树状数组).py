# 逆序对数量(值域树状数组)
# 给定一个长度为n的数组arr
# 如果 i < j 且 arr[i] > arr[j]
# 那么(i,j)就是一个逆序对
# 求arr中逆序对的数量
# 1 <= n <= 5 * 10^5
# 1 <= arr[i] <= 10^9
# 测试链接 : https://www.luogu.com.cn/problem/P1908

import sys

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    arr = data[1:1+n]

    # 离散化处理：排序并去重
    sorted_arr = sorted(arr)
    unique_sorted = []
    m = 0
    # 手动去重，构建有序唯一数组
    for num in sorted_arr:
        if not unique_sorted or unique_sorted[-1] != num:
            unique_sorted.append(num)
            m += 1
    
    # 构建值到排名的映射（排名从1开始）
    rank_map = {}
    for idx, num in enumerate(unique_sorted, start=1):
        rank_map[num] = idx

    # 将原数组转换为排名数组
    arr_rank = [rank_map[num] for num in arr]

    tree = [0] * (n + 1)
    # 定义树状数组操作函数
    def lowbit(i):
        return i & (-i)

    def add(i, v):
        while i <= n:
            tree[i] += v
            i += lowbit(i)
        
    def query(i):
        # 查询[1, i] 区间和
        ans = 0
        while i > 0:
            ans += tree[i]
            i -= lowbit(i)
        return ans

    # 从右往左遍历数组，统计逆序对
    ans = 0
    for i in range(n - 1, -1, -1):
        rk = arr_rank[i]
        if rk > 1:
            ans += query(rk - 1)
        add(rk, 1)
    
    print(ans)



if __name__ == '__main__':
    main()
