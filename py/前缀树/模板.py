import sys


# class TrieNode:
#     def __init__(self):
#         self.Pass = 0
#         self.End = 0
#         self.Next = [None] * 26


# class Trie1:
#     def __init__(self):
#         self.root = TrieNode()

#     def insert(self, word: str) -> None:
#         node = self.root
#         node.Pass += 1
#         for c in word:
#             path = ord(c) - ord('a')
#             if node.Next[path] is None:
#                 node.Next[path] = TrieNode()
#             node = node.Next[path]
#             node.Pass += 1
#         node.End += 1

#     # 查询前缀树里，word单词出现了几次
#     def countWordsEqualTo(self, word: str) -> int:
#         node = self.root
#         for c in word:
#             path = ord(c) - ord('a')
#             if node.Next[path] is None:
#                 return 0
#             node = node.Next[path]
#         return node.End
    
#     # 查询前缀树里，有多少单词以pre做前缀
#     def countWordsStartingWith(self, pre: str) -> int:
#         node = self.root
#         for c in pre:
#             path = ord(c) - ord('a')
#             if node.Next[path] is None:
#                 return 0
#             node = node.Next[path]
#         return node.Pass
    
#     # 如果之前word插入过前缀树，那么此时删掉一次
#     # 如果之前word没有插入过前缀树，那么什么也不做
#     def erase(self, word: str) -> None:
#         if self.countWordsEqualTo(word) == 0:
#             return
        
#         node = self.root
#         node.Pass -= 1
#         for c in word:
#             path = ord(c) - ord('a')
#             node.Next[path].Pass -= 1
#             if node.Next[path].Pass == 0:
#                 node.Next[path] = None
#                 return
#             node = node.Next[path]
#         node.End -= 1
#         return



class TrieNode:
    def __init__(self):
        self.pass_count = 0  # 经过该节点的单词数量
        self.end_count = 0   # 以该节点结尾的单词数量
        self.nexts = {}      # 子节点哈希表，key为字符，value为TrieNode


class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        """插入一个单词"""
        node = self.root
        node.pass_count += 1
        for char in word:  # 从左往右遍历字符
            if char not in node.nexts:
                node.nexts[char] = TrieNode()
            node = node.nexts[char]
            node.pass_count += 1
        node.end_count += 1

    def erase(self, word: str) -> None:
        """删除一个单词（如果有的话）"""
        if self.count_words_equal_to(word) > 0:
            node = self.root
            node.pass_count -= 1
            for char in word:
                next_node = node.nexts[char]
                next_node.pass_count -= 1
                # 如果下一个节点的pass变为0，说明没有单词经过它了，可以直接删除
                if next_node.pass_count == 0:
                    del node.nexts[char]
                    return
                node = next_node
            node.end_count -= 1

    def count_words_equal_to(self, word: str) -> int:
        """查询完全等于word的单词数量"""
        node = self.root
        for char in word:
            if char not in node.nexts:
                return 0
            node = node.nexts[char]
        return node.end_count

    def count_words_starting_with(self, prefix: str) -> int:
        """查询以prefix为前缀的单词数量"""
        node = self.root
        for char in prefix:
            if char not in node.nexts:
                return 0
            node = node.nexts[char]
        return node.pass_count


# 使用示例
if __name__ == "__main__":
    trie = Trie()

    # 插入单词
    trie.insert("apple")
    trie.insert("app")
    trie.insert("application")
    trie.insert("banana")

    # 查询
    print(trie.count_words_equal_to("app"))        # 1
    # 3 (app, apple, application)
    print(trie.count_words_starting_with("app"))
    print(trie.count_words_starting_with("appl"))  # 2 (apple, application)

    # 删除
    trie.erase("app")
    print(trie.count_words_equal_to("app"))        # 0
    print(trie.count_words_starting_with("app"))   # 2 (apple, application)
