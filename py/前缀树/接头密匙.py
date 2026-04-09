from typing import List

class TrieNode:
    def __init__(self):
        self.childern = {}
        self.pass_count = 0



class Solution:
    def __init__(self):
        self.root = None

    def build(self):
        self.root = TrieNode()


    def countConsistentKeys(self , b: List[List[int]], a: List[List[int]]) -> List[int]:
        self.build()
        for nums in a:
            diff_str = ""
            for i in range(1, len(nums)):
                diff_str += str(nums[i] - nums[i - 1]) + '#'
            self._insert(diff_str)

        ans = []
        for nums in b:
            diff_str = ""
            for i in range(1, len(nums)):
                diff_str += str(nums[i] - nums[i - 1]) + '#'
            ans.append(self._count(diff_str))
        self.clear()
        return ans

    def _path(self, c: str) -> int:
        if c == '#':
            return 10
        elif c == '-':
            return 11
        else:
            return ord(c) - ord('0')

    def _insert(self, word: str) -> None:
        cur = self.root
        cur.pass_count += 1
        for c in word:
            if c not in cur.childern:
                cur.childern[c] = TrieNode()
            cur = cur.childern[c]
            cur.pass_count += 1


    def _count(self, word: str) -> int:
        cur = self.root
        for c in word:
            if c not in cur.childern:
                return 0
            cur = cur.childern[c]
        return cur.pass_count

    def clear(self):
        self.root = None
