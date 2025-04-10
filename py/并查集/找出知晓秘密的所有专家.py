# 找出知晓秘密的所有专家
# 给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号
# 另外给你一个下标从 0 开始的二维整数数组 meetings
# 其中 meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会
# 一个专家可以同时参加 多场会议 。最后，给你一个整数 firstPerson
# 专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson
# 接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播
# 更正式的表达是，每次会议，如果专家 xi 在时间 timei 时知晓这个秘密
# 那么他将会与专家 yi 分享这个秘密，反之亦然。秘密共享是 瞬时发生 的
# 也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享
# 在所有会议都结束之后，返回所有知晓这个秘密的专家列表
# 你可以按 任何顺序 返回答案
# 链接测试 : https://leetcode.cn/problems/find-all-people-with-secret/


import sys

father = []
secret = []

def findAllPeople(n, meetings, firstPerson):
    global father, secret
    def build(n, firstPerson):
        global father, secret
        father = [i for i in range(n)]
        secret = [False for _ in range(n)]
        father[firstPerson] = 0
        secret[0] = True

    def find(i):
        global father
        if i != father[i]:
            father[i] = find(father[i])
        return father[i]

    def union(x, y):
        global father, secret
        fx = find(x)
        fy = find(y)
        if fx != fy:
            father[fx] = fy
            secret[fy] |= secret[fx]

    build(n, firstPerson)
    meetings.sort(key=lambda x: x[2])
    m = len(meetings)
    l = r = 0
    while l < m:
        while r + 1 < m and meetings[l][2] == meetings[r + 1][2]:
            r += 1

        for i in range(l, r + 1):
            union(meetings[i][0], meetings[i][1])
        for i in range(l, r + 1):
            a = meetings[i][0]
            b = meetings[i][1]
            if not secret[find(a)]:
                father[a] = a
            if not secret[find(b)]:
                father[b] = b
        l = r + 1
    ans = []
    for i in range(n):
        if secret[find(i)]:
            ans.append(i)
    return ans
            

def main() -> None:
    n, m, firstPerson = map(int, sys.stdin.readline().strip().split())
    meetings = [list(map(int, sys.stdin.readline().strip().split())) for _ in range(m)]
    print(findAllPeople(n, meetings, firstPerson))


if __name__ == '__main__':
    main()
