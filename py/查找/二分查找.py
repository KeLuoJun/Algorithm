# \查找\线性查找\二分查找
class LinearSearch:
    def __init__(self, arr):
        self.arr = arr
        self.n = len(arr)

    def search(self, x):
        for i in range(self.n):
            if self.arr[i] == x:
                return i + 1
        return -1
    

class BinarySearch:
    def __init__(self, arr):
        self.arr = sorted(arr)
        self.n = len(arr)

    def search(self, x):
        l, r = 0, self.n - 1
        while l <= r:
            mid = (l + r) // 2
            if self.arr[mid] == x:
                return mid + 1
            elif self.arr[mid] < x:
                l = mid + 1
            else:
                r = mid - 1
        return -1
            
def main() -> None:
    arr = list(map(int, input("请输入待查找的数组：\n").split()))
    x = int(input("请输入待查找元素："))
    linear_search = LinearSearch(arr)
    print("线性查找结果：", linear_search.search(x))


if __name__ == '__main__':
    main()
