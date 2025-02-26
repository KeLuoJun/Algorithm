# 矩阵二分查找
import heapq
class SearchMartix:
    def __init__(self, matrix):
        self.matrix = matrix
        self.rows = len(matrix)
        self.cols = len(matrix[0])
        self.sorted_matrix = []
        self._merge()
    # 将矩阵转换为有序列表
    # 归并排序
    def _merge(self):
        heap = []
        for i in range(self.rows):
            heapq.heappush(heap, (self.matrix[i][0], i, 0))
        while heap:
            num, row, col = heapq.heappop(heap)
            self.sorted_matrix.append(num)
            if col + 1 < self.cols:
                heapq.heappush(heap, (self.matrix[row][col + 1], row, col + 1))
        print(self.sorted_matrix)
        
    def find(self, target):
        return f'{target}在矩阵中' if self._binary_search(target) else \
        f'{target}不在矩阵中'

    # 二分查找
    def _binary_search(self, target):
        l, r = 0, len(self.sorted_matrix) - 1
        while l <= r:
            mid = (l + r) // 2
            if self.sorted_matrix[mid] == target:
                return True
            elif self.sorted_matrix[mid] < target:
                l = mid + 1
            else:
                r = mid - 1
        return False
        

def main() -> None:
    row, col = map(int, input("请输入矩阵的行数和列数：").split())
    print("Attention: 输入的矩阵元素必须为升序！")
    matrix = [list(map(int, input(f"请输入第{i + 1}行：").split())) for i in range(row)]
    search_martix = SearchMartix(matrix)
    x = int(input("请输入待查找元素："))
    print(search_martix.find(x))

if __name__ == '__main__':
    main()