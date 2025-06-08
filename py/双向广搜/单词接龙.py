# 单词接龙
# 字典 wordList 中从单词 beginWord 和 endWord 的 转换序列
# 是一个按下述规格形成的序列 beginWord -> s1 -> s2 -> ... -> sk ：
# 每一对相邻的单词只差一个字母。
# 对于 1 <= i <= k 时，每个 si 都在 wordList 中
# 注意， beginWord 不需要在 wordList 中。sk == endWord
# 给你两个单词 beginWord 和 endWord 和一个字典 wordList
# 返回 从 beginWord 到 endWord 的 最短转换序列 中的 单词数目
# 如果不存在这样的转换序列，返回 0 。
# 测试链接 : https://leetcode.cn/problems/word-ladder/

import sys
from typing import Set, List
def ladderLength(beginWord: str, endWord: str, wordList: List[str]):
    if endWord not in wordList:
        return 0

    wordList = set(wordList)
    # 数量小的一侧，数量大的一侧，数量小的一侧所扩展出的下一层列表
    smallLevel, bigLevel, nextLevel = set(), set(), set()
    smallLevel.add(beginWord)
    bigLevel.add(endWord)
    length = 2
    while smallLevel:
        for word in smallLevel:
            # 从小侧扩展
            for i in range(len(word)):
                for c in 'abcdefghijklmnopqrstuvwxyz':
                    if c == word[i]:
                        continue
                    new_word = word[:i] + c + word[i + 1:]
                    if new_word in bigLevel:
                        return length
                    if new_word in wordList:
                        wordList.remove(new_word)
                        nextLevel.add(new_word)
        if len(nextLevel) < len(bigLevel):
            smallLevel = nextLevel
        else:
            smallLevel, bigLevel = bigLevel, nextLevel
        nextLevel = set()
        length += 1
    return 0

def main() -> None:
    beginWord, endWord = sys.stdin.readline().split()
    wordList = list(map(str, sys.stdin.readline().split()))
    print(ladderLength(beginWord, endWord, wordList))



if __name__ == '__main__':
    main()
