# 简单哈希表
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
        
        # Create new node
        new_node = Node(key, value)
        
        # If the slot is empty, add the first node
        if self.table[index] is None:
            self.table[index] = new_node
            return
            
        # If key exists, update its value
        current = self.table[index]
        while current is not None:
            if current.key == key:
                current.value = value
                return
            current = current.next
            
        # Add new node at the beginning of the chain
        new_node.next = self.table[index]
        self.table[index] = new_node

    def get(self, key):
        index = self._hash(key)
        current = self.table[index]
        
        # Traverse the chain to find the key
        while current is not None:
            if current.key == key:
                return current.value
            current = current.next
        return None

    def remove(self, key):
        index = self._hash(key)
        
        # If chain is empty
        if self.table[index] is None:
            return
            
        # If key is in the first node
        if self.table[index].key == key:
            self.table[index] = self.table[index].next
            return
            
        # Search for key in the rest of the chain
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

# Example usage:
if __name__ == "__main__":
    hash_table = HashTable(10)
    
    # Insert some values
    hash_table.insert("apple", 5)
    hash_table.insert("banana", 8)
    hash_table.insert("orange", 3)
    hash_table.insert("grape", 2)
    
    # Test the operations
    print("Initial hash table:")
    print(hash_table)
    
    print("\nGetting value for 'apple':", hash_table.get("apple"))
    
    print("\nRemoving 'banana'")
    hash_table.remove("banana")
    
    print("\nUpdated hash table:")
    print(hash_table)