# 去除重复字母保证剩余字符串的字典序最小
# 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
# 需保证 返回结果的字典序最小
# 要求不能打乱其他字符的相对位置
# 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/

import sys

def solve(s):
    cnts = [0] * 26
    enter = [False] * 26
    stack = [] 
    for cha in s:
        cnts[ord(cha) - ord('a')] += 1
    for cur in s:
        idx = ord(cur) - ord('a')
        if not enter[idx]:
            while stack and stack[-1] > cur \
                  and cnts[ord(stack[-1]) - ord('a')] > 0:
                remove = stack.pop()
                enter[ord(remove) - ord('a')] = False
            stack.append(cur)
            enter[idx] = True
        cnts[idx] -= 1
    return ''.join(stack)
        

def main():
    s = sys.stdin.readline().strip()
    print(solve(s))
    

if __name__ == '__main__':
    main()
