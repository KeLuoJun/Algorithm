from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity: int):
        """
        初始化LRU缓存
        :param capacity: 缓存的最大容量
        """
        self.capacity = capacity
        # 使用OrderedDict来保存缓存的键值对
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        """
        获取缓存中的值。如果键存在，将其移动到最近使用的位置
        :param key: 要获取的键
        :return: 键对应的值，如果不存在则返回-1
        """
        if key not in self.cache:
            return -1
        
        # 将访问的元素移动到OrderedDict的末尾（最近使用）
        value = self.cache.pop(key)
        self.cache[key] = value
        return value

    def put(self, key: int, value: int) -> None:
        """
        将键值对放入缓存。如果键已存在，更新其值；如果缓存已满，删除最久未使用的元素
        :param key: 键
        :param value: 值
        """
        # 如果键已存在，先删除旧的键值对
        if key in self.cache:
            self.cache.pop(key)
        # 如果缓存已满且要插入新键，删除最久未使用的元素
        elif len(self.cache) >= self.capacity:
            # popitem(last=False)删除并返回第一个元素（最久未使用）
            self.cache.popitem(last=False)
        
        # 在OrderedDict末尾添加新的键值对（最近使用）
        self.cache[key] = value

    def display(self) -> None:
        """
        显示缓存中的所有元素，按使用时间从旧到新排序
        """
        print("\n当前缓存状态:")
        if not self.cache:
            print("空")
            return
        
        for key, value in self.cache.items():
            print(f"键: {key}, 值: {value}")

def main():
    # 创建容量为3的LRU缓存
    cache = LRUCache(3)
    
    while True:
        print("\n=== LRU缓存操作 ===")
        print("1. 添加元素 (put)")
        print("2. 获取元素 (get)")
        print("3. 显示缓存")
        print("4. 退出")
        
        choice = input("\n请选择操作 (1-4): ").strip()
        
        if choice == '1':
            try:
                key = int(input("请输入键: "))
                value = int(input("请输入值: "))
                cache.put(key, value)
                print("添加成功！")
                cache.display()
            except ValueError:
                print("请输入有效的数字！")
        
        elif choice == '2':
            try:
                key = int(input("请输入要获取的键: "))
                value = cache.get(key)
                if value != -1:
                    print(f"获取的值为: {value}")
                else:
                    print("键不存在！")
                cache.display()
            except ValueError:
                print("请输入有效的数字！")
        
        elif choice == '3':
            cache.display()
        
        elif choice == '4':
            print("退出程序")
            break
        
        else:
            print("无效的选择，请重试！")

if __name__ == "__main__":
    main()