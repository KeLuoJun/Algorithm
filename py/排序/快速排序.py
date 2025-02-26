# 随机快排
import random

class QuickSort:
    def __init__(self, arr):
        self.arr = arr  
        self.n = len(arr)  
        self.first = None  # 小于基准值x的越界左边界
        self.last = None   # 大于基准值x的越界右边界
    
    def _swap(self, i, j):
        self.arr[i], self.arr[j] = self.arr[j], self.arr[i]

    def _partition(self, l, r, x):
        """将数组[l, r]分区，使得所有小于x的元素在左边，所有大于x的元素在右边"""
        self.first = l  
        self.last = r  
        i = l
        while i <= self.last:
            if self.arr[i] == x:
                i += 1  # 如果当前元素等于x，继续下一个元素
            elif self.arr[i] < x:
                self._swap(i, self.first)  # 交换当前元素和小于x的边界元素
                self.first += 1  # 更新小于x的边界
                i += 1
            else:
                self._swap(i, self.last)  # 交换当前元素和大于x的边界元素
                self.last -= 1  # 更新大于x的边界

    def _quick_sort(self, l, r):
        if l >= r:
            return  
        x = self.arr[random.randint(l, r)] 
        self._partition(l, r, x)  # 对数组进行分区
        left, right = self.first - 1, self.last + 1  # 计算新的子数组边界
        self._quick_sort(l, left)  # 对左边的子数组进行快速排序
        self._quick_sort(right, r)  # 对右边的子数组进行快速排序

    def get_sorted_arr(self):
        self._quick_sort(0, self.n - 1)  
        return self.arr  

def main() -> None:
    arr = list(map(int, input("请输入待排序数组：\n").split()))  
    quick_sort = QuickSort(arr)  
    print("快速排序结果：\n", quick_sort.get_sorted_arr())  

if __name__ == '__main__':
    main()  