# 升序三元组数量
# 给定一个数组arr，如果i < j < k且arr[i] < arr[j] < arr[k]
# 那么称(i, j, k)为一个升序三元组
# 返回arr中升序三元组的数量
# 测试链接 : https://www.luogu.com.cn/problem/P1637


import sys

def main() -> None:
    data = list(map(int, sys.stdin.read().split()))
    n = data[0]
    arr = data[1:1+n]

    # 离散化处理：排序并去重
    sorted_arr = sorted(arr)
    unique_sorted = []
    m = 0
    for num in sorted_arr:
        if not unique_sorted or num != unique_sorted[-1]:
            unique_sorted.append(num)
            m += 1

    # 构建值到排名的映射（排名从1开始）
    rank_map = {}
    for idx, num in enumerate(unique_sorted, start=1):
        rank_map[num] = idx
    rank_arr = [rank_map[num] for num in arr] 

    tree1 = [0] * (n + 1)
    tree2 = [0] * (n + 1) 

    # 定义树状数组操作函数
    def lowbit(i):
        return i & (-i)
    
    def add(tree, i, v):
        while i <= n:
            tree[i] += v
            i += lowbit(i)
    
    def query(tree, i):
        # 查询[1, i] 区间和
        ans = 0
        while i > 0:
            ans += tree[i]
            i -= lowbit(i)
        return ans
    
    ans = 0
    for num in rank_arr:
        # 查询以当前数字作为结尾的升序三元组熟练
        ans += query(tree2, num - 1)
        # 更新以当前值为结尾的升序一元组数量
        add(tree1, num, 1)
        # 更新以当前值做结尾的升序二元组数量
        add(tree2, num, query(tree1, num - 1))
    print(ans)


if __name__ == '__main__':
    main()



