# 字符串转化
# 给出两个长度相同的字符串str1和str2
# 请你帮忙判断字符串str1能不能在 零次 或 多次 转化后变成字符串str2
# 每一次转化时，你可以将str1中出现的所有相同字母变成其他任何小写英文字母
# 只有在字符串str1能够通过上述方式顺利转化为字符串str2时才能返回true
# 测试链接 : https://leetcode.cn/problems/string-transforms-into-another-string/

class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        if str1 == str2: return True
        # map[x] : str2中字符x的词频
        map = [0] * 26
        # kinds : str2中字符的种类数
        kinds = 0
        for c in str2:
            if map[c - 'a'] == 0:
                kinds += 1
            map[c - 'a'] += 1
        if kinds == 26:
            return False
        # map[x] = y : str1中的字符x上次出现在str1中的y位置
        map = [-1] * 26
        for i in len(str1):
            cur = str1[i] - 'a'
            if map[cur] != -1 and str2[map[cur]] != str2[i]:
                return False
            map[cur] = i
        return True
            


