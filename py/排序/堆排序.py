# 堆排序
class MAXHeap:
    def __init__(self, arr):
        self.heap = arr
        self.n = len(arr)

    def _swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]

    def _heap_insert(self, i):
        while self.heap[i] > self.heap[(i - 1) // 2]:
            self._swap(i, (i - 1) // 2)
            i = (i - 1) // 2
    
    def _heapify(self, i, size):
        l = i * 2 + 1
        while l < size:
            best = l + 1 if l + 1 < size and \
            self.heap[l + 1] > self.heap[l] else l
            best = best if self.heap[best] > self.heap[i] else i
            if best == i:
                break
            self._swap(i, best)
            i = best
            l = i * 2 + 1

    def _heap_sort(self):
        for i in range(self.n - 1, -1, -1):
            self._heapify(i, self.n)
        size = self.n
        while size > 1:
            size -= 1
            self._swap(0, size)
            self._heapify(0, size)

    def get_sorted_arr(self):
        self._heap_sort()
        return self.heap

    def get_k_smallest(self, k):
        if k > self.n:
            return "输入的k值过大"
        return self.heap[:k]


class MINHeap:
    def __init__(self, arr):
        self.heap = arr
        self.n = len(arr)

    def _swap(self, i, j):
        self.heap[i], self.heap[j] = self.heap[j], self.heap[i]
    
    def _heap_insert(self, i):
        while self.heap[i] < self.heap[(i - 1) // 2]:
            self._swap(i, (i - 1) // 2)
            i = (i - 1) // 2
        
    def _heapify(self, i, size):
        l = i * 2 + 1
        while l < size:
            best = l + 1 if l + 1 < size and \
            self.heap[l + 1] < self.heap[l] else l
            best = best if self.heap[best] < self.heap[i] else i
            if best == i:
               break
        self._swap(i, best)
        i = best
        l = i * 2 + 1

    def _heap_sort(self):
        for i in range(self.n - 1, -1, -1):
            self._heapify(i, self.n)
        size = self.n
        while size > 1:
            size -= 1
            self._swap(0, size)
            self._heapify(0, size)

    def get_sorted_arr(self):
        self._heap_sort()
        return self.heap


if __name__ == '__main__':
    arr = list(map(int, input("请输入待排序数组：\n").split()))
    heap_1 = MAXHeap(arr)
    heap_2 = MINHeap(arr)
    # print("堆排序结果(大根堆)：\n", heap_1.get_sorted_arr())
    # print("堆排序结果(小根堆)：\n", heap_2.get_sorted_arr())
    k = int(input("请输入要查找的最小的k个元素："))
    print("最小的k个元素：\n", heap_1.get_k_smallest(k))