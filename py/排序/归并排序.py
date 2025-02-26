# 归并排序
class MergeSort:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)
        
    def _merge(self, l, m, r):
        i, a, b = l, l, m + 1
        help = [0] * self.n
        while a <= m and b <= r:
            if self.arr[a] < self.arr[b]:
                help[i] = self.arr[a]
                a += 1
            else:
                help[i] = self.arr[b]
                b += 1
            i += 1
        while a <= m:
            help[i] = self.arr[a]
            a += 1
            i += 1
        while b <= r:
            help[i] = self.arr[b]
            b += 1
            i += 1
        # 复原
        for j in range(l, r + 1):
            self.arr[j] = help[j]
    
    def _merge_sort(self, l, r):
        if l == r:
            return
        m = (l + r) // 2
        self._merge_sort(l, m)
        self._merge_sort(m + 1, r)
        self._merge(l, m, r)

    def get_sorted_arr(self):
        self._merge_sort(0, self.n - 1)
        return self.arr
    
def main() -> None:
    arr = list(map(int, input("请输入待排序数组：\n").split()))
    merge_sort = MergeSort(arr)
    print("归并排序结果：\n", merge_sort.get_sorted_arr())


if __name__ == '__main__':
    main()

