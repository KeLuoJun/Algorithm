# 刀砍毒杀怪兽问题
# 怪兽的初始血量是一个整数hp，给出每一回合刀砍和毒杀的数值cuts和poisons
# 第i回合如果用刀砍，怪兽在这回合会直接损失cuts[i]的血，不再有后续效果
# 第i回合如果用毒杀，怪兽在这回合不会损失血量，但是之后每回合都损失poisons[i]的血量
# 并且你选择的所有毒杀效果，在之后的回合都会叠加
# 两个数组cuts、poisons，长度都是n，代表你一共可以进行n回合
# 每一回合你只能选择刀砍或者毒杀中的一个动作
# 如果你在n个回合内没有直接杀死怪兽，意味着你已经无法有新的行动了
# 但是怪兽如果有中毒效果的话，那么怪兽依然会在血量耗尽的那回合死掉
# 返回至少多少回合，怪兽会死掉
# 数据范围 : 
# 1 <= n <= 10^5
# 1 <= hp <= 10^9
# 1 <= cuts[i]、poisons[i] <= 10^9


def check(mid, hp):
    k = min(n, mid)
    for i, j in zip(range(k), range(1, k)):
        hp -= max(cuts[i], (mid - j) * poisons[i])
        if hp <= 0:
            return True
    return False

def solution(hp, cuts, poisons):
    l, r = 0, hp + 1
    ans = -1
    while l <= r:
        mid = (l + r) // 2
        if check(mid, hp):
            ans = mid 
            r = mid - 1
        else:
            l = mid + 1
    return ans


hp, n = list(map(int, input().strip()))
cuts = list(map(int, input().strip()))
poisons = list(map(int, input().strip()))

print(solution(hp, cuts, poisons))