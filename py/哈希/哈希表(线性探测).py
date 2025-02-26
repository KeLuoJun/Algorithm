# \哈希\线性探测哈希表
class HashTable:
    def __init__(self, capacity=100):
        self.capacity = capacity
        self.table = [None] * capacity
        self.size = 0
        self.load_factor = 0.75

    def _hash(self, key):
        return hash(key) % self.capacity


    def _resize(self):
        capacity_new = int(self.capacity * 1.5)
        self.capacity = capacity_new
        hash_table_new = [None] * self.capacity


        for (key, value) in self.table:
            if key is not None:
                hash_k = self._hash(key)
                if hash_table_new[hash_k] is not None:
                    hash_table_new[hash_k] = (key, value)
                else:
                    for i in range(self.capacity):
                        hash_k = self._hash(hash_k + 1) 
                        if hash_table_new[hash_k] is not None:
                            hash_table_new[hash_k] = (key, value)
                            break
        self.table = hash_table_new


    def insert(self, key, value):
        index = self._hash(key)
        # 当存储数据与哈希表容量比大于载荷因子时，进行扩容
        if self.size / self.capacity > self.load_factor:
            self._resize()

        while self.table[index] is not None:
            index = self._hash(index + 1)
        self.table[index] = (key, value)
        self.size += 1
        print(f"插入成功！")

    def get(self, key):
        index = self._hash(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                return self.table[index][1]
            index = self._hash(index + 1) 
        return None
    
    def remove(self, key):
        index = self._hash(key)
        while self.table[index] is not None:
            if self.table[index][0] == key:
                self.table[index] = None
                self.size -= 1
                return True
            index = self._hash(index + 1) 
        return False
    
    def __str__(self):
        result = []
        for i, pair in enumerate(self.table):
            if pair is not None:
                result.append(f'{i}: {pair}')
        return "\n".join(result)

def mune():
    print("|------- 菜单 -------|")
    print("|--- [1] 插入元素 ---|")
    print("|--- [2] 查询元素 ---|")
    print("|--- [3] 删除元素 ---|")
    print("|--- [4] 显示元素 ---|")
    print("|--- [0] 退出系统 ---|")

def main() -> None:
    choice = None
    hash_table = HashTable()
    while True:
        mune()
        choice = int(input("请输入你的选择："))
        if choice == 1:
            key, value = map(int, input("请输入键值对：").split())
            hash_table.insert(key, value)
        elif choice == 2:
            key = int(input("请输入键值："))
            print(f"{key}对应的值是：", hash_table.get(key))
        elif choice == 3:
            key = int(input("请输入键值："))
            if hash_table.remove(key):
                print("删除成功！")
            else:
                print("key不存在，删除失败！")
        elif choice == 4:
            print(hash_table)
        elif choice == 0:
            break
        else:
            print("输入错误，请重新输入")

if __name__ == '__main__':
    main()

