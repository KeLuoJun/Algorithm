# 哈希表(拉链表)
class Node:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.next = None

class HashTable:
    def __init__(self, size=100):
        self.size = size
        self.table = [None] * size

    def _hash(self, key):
        return hash(key) % self.size

    def insert(self, key, value):
        index = self._hash(key)
        
        new_node = Node(key, value)
        
        if self.table[index] is None:
            self.table[index] = new_node
            return
            
        current = self.table[index]
        while current.next is not None:
            if current.key == key:
                current.value = value
                return
            current = current.next
        current.next = new_node

    def get(self, key):
        index = self._hash(key)
        current = self.table[index]
        

        while current is not None:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def remove(self, key):
        index = self._hash(key)
        
        if self.table[index] is None:
            return
            
        if self.table[index].key == key:
            self.table[index] = self.table[index].next
            return
            
        current = self.table[index]
        while current.next is not None:
            if current.next.key == key:
                current.next = current.next.next
                return
            current = current.next

    def __str__(self):
        result = []
        for i in range(self.size):
            if self.table[i] is not None:
                chain = []
                current = self.table[i]
                while current is not None:
                    chain.append(f"({current.key}, {current.value})")
                    current = current.next
                result.append(f"Index {i}: {' -> '.join(chain)}")
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