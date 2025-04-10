# 航班预订统计
# 这里有 n 个航班，它们分别从 1 到 n 进行编号。
# 有一份航班预订表 bookings ，
# 表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi]
# 意味着在从 firsti 到 lasti 
#（包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
# 请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
# 测试链接 : https://leetcode.cn/problems/corporate-flight-bookings/

import sys
from typing import List
def corpFlightBookings(bookings: List[List[int]], n: int):
    diff = [0] * (n + 2)
    # 设置差分数组，每一个操作对应两个设置
    for book in bookings:
        diff[book[0]] += book[2]
        diff[book[1] + 1] -= book[2]
    # 加工前缀和
    for i in range(1, len(diff)):
        diff[i] += diff[i - 1]
    ans = [0] * n
    for i in range(n):
        ans[i] = diff[i + 1]
    return ans



def main() -> None:
    n, m = map(int, sys.stdin.readline().strip().split())
    bookings = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(m)]
    print(corpFlightBookings(bookings, n))


if __name__ == '__main__':
    main()
