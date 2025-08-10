# 参加会议的最多员工数
# 一个公司准备组织一场会议，邀请名单上有 n 位员工
# 公司准备了一张 圆形 的桌子，可以坐下 任意数目 的员工
# 员工编号为 0 到 n - 1 。每位员工都有一位 喜欢 的员工
# 每位员工 当且仅当 他被安排在喜欢员工的旁边，他才会参加会议
# 每位员工喜欢的员工 不会 是他自己。给你一个下标从 0 开始的整数数组 favorite
# 其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目
# 测试链接 : https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/

import sys
from typing import List
from collections import deque


def maximumInvitations(favorite: List[int]) -> int:
    # 图 : favorite[a] = b : a -> b
    n = len(favorite)
    



def main() -> None:
    favorite = list(map(int, sys.stdin.readline().strip().split()))
    result = maximumInvitations(favorite)
    print(result)


if __name__ == '__main__':
    main()

