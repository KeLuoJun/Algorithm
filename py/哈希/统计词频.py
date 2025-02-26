# 统计词频(哈希表)
import re
from collections import defaultdict

class WordFrequencyCounter:
    def __init__(self):
        self.word_counts = defaultdict(int)

    def _preprocess_text(self, text):
        """
        预处理文本：
        1. 转换为小写
        2. 移除标点符号
        3. 分割成单词列表
        """
        text = text.lower()
        text = re.sub(r'[^a-z\s]', '', text)
        words = [word.strip() for word in text.split()]
        return [word for word in words if word]
    
    def count_words(self, text):
        """统计文本中每个单词的出现次数"""
        words = self._preprocess_text(text)
        for word in words:
            self.word_counts[word] += 1
        return dict(self.word_counts)
    
    def get_top_words(self, n):
        """获取出现次数最多的n个单词"""
        return sorted(self.word_counts.items(), key=lambda x: x[1], reverse=True)[:n]
    
    def display_statistics(self):
        """显示词频统计信息"""
        total_words = sum(self.word_counts.values())
        unique_words = len(self.word_counts)

        print(f"\n词频统计结果：")
        print(f"总单词数：{total_words}")
        print(f"不同单词数：{unique_words}")
        print("\n出现次数最多的10个单词：")

        for word, count in self.get_top_words(10):
            percentage = (count / total_words) * 100
            print(f"'{word}': {count} 次 ({percentage:.2f}%)")

def main() -> None:
    counter = WordFrequencyCounter()
    print("请选择输入方式：")
    print("1. 从文件读取")
    print("2. 直接输入文本")

    choice = int(input("请输入选择 (1 或 2): ").strip())
    if choice == 1:
        filename = input("请输入文件路径：(路径不带引号)").strip()
        try:
            with open(filename, 'r', encoding='utf-8') as file:
                text = file.read()
        except Exception as e:
            print(f"读取文件失败：{e}")
            return
    else:
        print("请输入文本（输入空行结束）：")
        lines = []
        while True:
            line = input()
            if not line:
                break
            lines.append(line)
        text = '\n'.join(lines)
    
    # 统计词频
    counter.count_words(text)
    
    # 显示统计结果
    counter.display_statistics()

if __name__ == '__main__':
    main()

    