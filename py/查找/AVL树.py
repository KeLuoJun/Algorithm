# AVL树(有序表)
# 左之树的值 < 根节点的值 < 右之树的值
# |左子树的高度 - 右子树的高度| <= 1
# 插入、删除、查询 O(logn)
import os
import msvcrt

class AVL:
    def __init__(self, arr=None):
        if arr == None:
            self.n = 10000
            self.arr = arr
        else:
            self.n = len(arr)
            self.arr = arr
            self._init_arr()
        
        self.cnt = 0
        self.head = 0  # 根节点
        self.key = [0] * self.n  # 节点的值
        self.height = [0] * self.n  # 节点的高度
        self.left = [0] * self.n  # 左子节点
        self.right = [0] * self.n  # 右子节点
        self.count = [0] * self.n  # 节点的词频
        self.size = [0] * self.n  # 当前节点子树的大小

    # 修正信息
    def _up(self, i):
        self.size[i] = self.size[self.left[i]] + self.size[self.right[i]] + self.count[i]
        self.height[i] = max(self.height[self.left[i]], self.height[self.right[i]]) + 1

    # i节点为头的树左旋，返回左旋后头节点的空间编号
    def _left_rotate(self, i):
        r = self.right[i]
        self.right[i] = self.left[r]
        self.left[r] = i
        self._up(i)
        self._up(r)
        return r
    
    # i节点为头的树右旋，返回右旋后头节点的空间编号
    def _right_rotate(self, i):
        l = self.left[i]
        self.left[i] = self.right[l]
        self.right[l] = i
        self._up(i)
        self._up(l)
        return l
    
    # 检查i节点为头的树是否违规
	# 如果命中了某种违规情况，就进行相应调整
	# 返回树的头节点的空间编号
    def _maintain(self, i):
        lh = self.height[self.left[i]]
        rh = self.height[self.right[i]]
        if lh - rh > 1:
            if self.height[self.left[self.left[i]]] >= self.height[self.right[i]]:
                # LL违规
                i = self._right_rotate(i)
            else:
                # LR违规
                self.left[i] = self._left_rotate(self.left[i])
                i = self._right_rotate(i)
        elif rh - lh > 1:
            if self.height[self.right[self.right[i]]] >= self.height[self.left[i]]:
                # RR违规
                i = self._left_rotate(i)
            else:
                # RL违规
                self.right[i] = self._right_rotate(self.right[i])
                i = self._left_rotate(i)
        return i
    # 初始化数组    
    def _init_arr(self):
        for i in range(self.n):
            self.head = self._add(self.arr[i])
    # 增加数字num，重复加入算多个词频
    def add(self, num):
        self.head = self._add_num(self.head, num)
        print("插入成功！")

    # 当前来到i号节点，num这个数字一定会加入以i为头的树
	# 树结构有可能变化，返回头节点编号
    def _add_num(self, i, num):
        if i == 0:
            self.cnt += 1
            self.key[self.cnt] = num
            self.count[self.cnt] = self.size[self.cnt] = self.height[self.cnt] = 1
            return self.cnt
        if self.key[i] == num:
            self.count[i] += 1
        elif self.key[i] > num:
            self.left[i] = self._add_num(self.left[i], num)
        else:
            self.right[i] = self._add_num(self.right[i], num)
        self._up(i)
        return self._maintain(i)
    
    # 删除数字num，如果有多个，只删掉一个
    def remove(self, num):
        if self.rank(num) != self.rank(num + 1):
            # 判断num值是否存在avl树中
            self.head = self._remove_num(self.head, num)
            print("删除成功！")
        else:
            print("该值不存在")
    
    # 当前来到i号节点，以i为头的树一定会减少1个num
	# 树结构有可能变化，返回头节点编号
    def _remove_num(self, i, num):
        if self.key[i] < num:
            self.right[i] = self._remove_num(self.right[i], num)
        elif self.key[i] > num:
            self.left[i] = self._remove_num(self.left[i], num)
        else:
            if self.count[i] > 1:
                self.count[i] -= 1
            else:
                if self.left[i] == 0 and self.right[i] == 0:
                    return 0
                elif self.left[i] != 0 and self.right[i] == 0:
                    i = self.left[i]
                elif self.left[i] == 0 and self.right[i] != 0:
                    i = self.right[i]
                else:
                    # 即有右树和左树
                    # 找到右树的最左节点（该节点的值与当前要删除的节点的值最接近）
                    most_left = self.right[i]
                    while self.left[most_left] != 0:
                        most_left = self.left[most_left]
                    self.right[i] = self._remove_mostleft(self.right[i], most_left)
                    self.left[most_left] = self.left[i]
                    self.right[most_left] = self.right[i]
                    i = most_left
        self._up(i)
        return self._maintain(i)
    
    # 删除节点后，同时命中LL和LR违规

    # 以i号节点为头的树上，最左节点的编号一定是mostLeft
	# 删掉这个节点，并保证树的平衡性，返回头节点的编号
    def _remove_mostleft(self, i, most_left):
        if i == most_left:
            # 找到了最左节点，直接返回右子树的头节点
            return self.right[i]
        else:
            self.left[i] = self._remove_mostleft(self.left[i], most_left)
            self._up(i)
            return self._maintain(i)
        
    # 查询num的排名，比num小的数字个数+1，就是num的排名
    def rank(self, num):
        return self._small(self.head, num) + 1

    def _small(self, i, num):
        if i == 0:
            return 0
        if self.key[i] >= num:
            return self._small(self.left[i], num)
        else:
            return self.size[self.left[i]] + 1 + self._small(self.right[i], num)
        
def mune():
    print("|------- 菜单 -------|")
    print("|----- [1] 插入 -----|")
    print("|----- [2] 删除 -----|")
    print("|----- [3] 查询 -----|")
    print("|----- [0] 退出 -----|")
    
def main() -> None:
    avl = AVL()
    while True:
        mune()
        choice = int(input())
        if choice == 1:
            x = int(input("请输入要插入的值："))
            avl.add(x)
        elif choice == 2:
            x = int(input("请输入要删除的值："))
            avl.remove(x)
        elif choice == 3:
            x = int(input("请输入要查询的值："))
            print(f"{x}在AVL树中的排名:", avl.rank(x))
        elif choice == 0:
            break
        else:
            print("输入错误，请重新输入")
        # print("按任意键继续...")
        # msvcrt.getch()
        # os.system('cls')
        

if __name__ == '__main__':
    main()