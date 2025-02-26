# 知识竞赛
# 最近部门要选两个员工去参加一个需要合作的知识竞赛，
# 每个员工均有一个推理能力值ai，以及一个阅读能力值bi
# 如果选择第i个人和第j个人去参加竞赛，
# 两人在推理方面的能力为X = (ai + aj)/2
# 两人在阅读方面的能力为Y = (bi + bj)/2
# 现在需要最大化他们表现较差一方面的能力
# 即让min(X,Y) 尽可能大，问这个值最大是多少
# 测试链接 : https://www.nowcoder.com/practice/2a9089ea7e5b474fa8f688eae76bc050

import sys
def solve():
    ability.sort(key=lambda x: abs(x[0] - x[1]))
    maxA, maxB = ability[0][0], ability[0][1]
    ans = 0
    for i in range(1, n):
        if ability[i][0] <= ability[i][1]:
            ans = max(ans, maxA + ability[i][0])
        else:
            ans = max(ans, maxB + ability[i][1])
        maxA, maxB = max(maxA, ability[i][0]), max(maxB, ability[i][1])

    return f'{ans / 2:.1f}'



if __name__ == '__main__':

    # 输入1：一次性读入输入
    input = sys.stdin.read
    data = input().split()
    n = int(data[0])
    ability = []
    idx = 1
    for _ in range(n):
        ai, bi = int(data[idx]), int(data[idx + 1])
        ability.append([ai, bi])
        idx += 1
    
    ## 输入2：逐行读入
    # n = int(input())
    # ability = []
    # for i in range(n):
    #     ipt = list(map(int, input().split()))
    #     ability.append(ipt)
    
    print(solve())      
    
