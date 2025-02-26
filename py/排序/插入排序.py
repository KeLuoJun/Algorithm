# 插入排序
class InsertSort:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)

    def _swap(self, i, j):
        self.arr[i], self.arr[j] = self.arr[j], self.arr[i]
    
    def _insert_sort(self):
        for i in range(1, self.n):
            for j in range(i-1, -1, -1):
                if self.arr[j] > self.arr[j + 1]:
                    self._swap(j, j + 1)
                else:
                    break
    
    def get_sorted_arr(self):
        self._insert_sort()
        return self.arr
    
if __name__=='__main__':
    arr = list(map(int, input("请输入待排序数组：\n").split()))
    insert_sort = InsertSort(arr)
    print("插入排序结果：\n", insert_sort.get_sorted_arr())