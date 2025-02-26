# 二元关系  Warshall算法
import numpy as np

class Relation:
    def __init__(self, size, relations):
        self.size = size
        self.relations = relations
        self.matrix = np.zeros((size, size), dtype=int)
        self._get_matrix()

    def _get_matrix(self):
        for u, v in self.relations:
            self.matrix[u][v] = 1
    
    def is_reflexive(self):
        """检查关系是否是自反的"""
        for i in range(self.size):
            if self.matrix[i][i] != 1:
                return False
        return True
    
    def is_irreflexive(self):
        """检查关系是否是非自反的"""
        for i in range(self.size):
            if self.matrix[i][i] == 1:
                return False
        return True
    
    def is_symmetric(self):
        """检查关系是否是对称的"""
        for i in range(self.size):
            for j in range(i + 1):
                if self.matrix[i][j] != self.matrix[j][i]:
                    return False
        return True

    def is_antisymmetric(self):
        """检查关系是否是反对称的"""
        for i in range(self.size):
            for j in range(self.size):
                if i != j and self.matrix[i][j] == 1 and self.matrix[j][i] == 1:
                    return False
        return True
    
    def is_transitive(self):
        """检查关系是否是传递的"""
        for i in range(self.size):
            for j in range(self.size):
                for k in range(self.size):
                    if self.matrix[i][k] == 1 and self.matrix[k][j] == 1:
                        if self.matrix[i][j] != 1:
                            return False
        return True
    
    def warshall_closure(self):
        """传递闭包"""
        closure = np.copy(self.matrix)
        for k in range(self.size):
            for i in range(self.size):
                for j in range(self.size):
                    closure[i][j] = closure[i][j] or (closure[i][k] and closure[k][j])
        return closure

def main():
    size = int(input("请输入二元关系R的大小:"))
    relations = []
    print("请输入二元关系R\n")
    for _ in range(size):
        relations.append(list(map(int, input().split())))
    r = Relation(size, relations)
    print("R是否满足自反:", r.is_reflexive())
    print("R是否满足非自反:", r.is_irreflexive())
    print("R是否满足对称:", r.is_symmetric())
    print("R是否满足反对称:", r.is_antisymmetric())
    print("R是否满足传递:", r.is_transitive())
    print("R的传递闭包:\n", r.warshall_closure())
    
if __name__ == "__main__":
    main()