# 贴纸拼词
# 我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
# 您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们
# 如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
# 返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1
# 注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的
# 并且 target 被选择为两个随机单词的连接。
# 测试链接 : https://leetcode.cn/problems/stickers-to-spell-word/


import sys
from collections import deque

def next_str(cur, s):
    ans = ''
    i = j = 0
    while i < len(cur):
        if j == len(s):
            ans += cur[i]
            i += 1
        elif cur[i] < s[j]:
            ans += cur[i]
            i += 1
        elif cur[i] > s[j]:
            j += 1
        else:
            i += 1
            j += 1
    return ans


def bfs(target, stickers):
    visited = set()
    graph = [[] for _ in range(26)]
    queue = deque()

    for s in stickers:
        s = ''.join(sorted(s))
        for i in range(len(s)):
            if i == 0 or s[i] != s[i - 1]:
                graph[ord(s[i]) - ord('a')].append(s)
    
    target = ''.join(sorted(target))
    visited.add(target)
    queue.append(target)
    level = 0
    while queue:
        level += 1
        for _ in range(len(queue)):
            cur = queue.popleft()
            for s in graph[ord(cur[0]) - ord('a')]:
                new_str = next_str(cur, s)
                if not new_str:
                    return level
                if new_str not in visited:
                    visited.add(new_str)
                    queue.append(new_str)
    return -1


def main() -> None:
    n = int(input())
    stickers = []
    for _ in range(n):
        stickers.append(input().strip())
    target = input().strip()
    print(bfs(target, stickers))


if __name__ == '__main__':
    main()



