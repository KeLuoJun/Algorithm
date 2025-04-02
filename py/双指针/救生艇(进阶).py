# 救生艇
# 给定数组 people
# people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
# 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
# 返回 承载所有人所需的最小船数
# 进阶：每艘船上的总体重必须为偶数 

import sys

def separte(people):
    '''奇偶分离，左奇，右偶'''
    n = len(people)
    l, r = 0, n - 1
    while l < r:
        while people[l] & 1 == 1:
            l += 1
        while people[r] & 1 == 0:
            r -= 1
        people[l], people[r] = people[r], people[l]
    if l == r:
        if people[l] & 1 == 0:
            l -= 1
        else:
            r += 1
    return people, l, r


def numRescueBoats(people, a, b, limit):
    people.sort()
    ans = 0
    while a <= b:
        sum = people[a] + people[b] if a < b else people[a]
        if sum <= limit:
            a += 1
            b -= 1
        else:
            b -= 1
        ans += 1

def solve(people: list[int], limit: int):
    n = len(people)
    people, l, r = separte(people)
    ans = numRescueBoats(people, 0, l, limit) + numRescueBoats(people, r + 1, n - 1, limit)
    return ans


def main() -> None:
    n, limit = map(int, sys.stdin.readline().strip().split())
    people = list(map(int, sys.stdin.readline().strip().split()))
    print(solve(people, limit))


if __name__ == '__main__':
    main()

