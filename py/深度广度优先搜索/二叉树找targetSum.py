from typing import List


class BiTNode:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def createBiTree(s, idx):
    if idx >= len(s):
        return None, idx
    
    if s[idx] == "#":
        return None, idx
    root = BiTNode(int(s[idx]))

    lest_tree, lest_idx = createBiTree(s, idx + 1)
    root.left = lest_tree

    right_tree, right_idx = createBiTree(s, lest_idx + 1)
    root.right = right_tree

    return root, right_idx

# 前序遍历
def preorder(root):
    if not root:
        return
    print(root.val, end='')
    preorder(root.left)
    preorder(root.right)


def check_path_sum(root, target):
    def isLeaf(node):
        return node and not node.left and not node.right
    
    def bfs(node: BiTNode, target: int, path: List[int], result: List[List[int]]) -> None:
        if not node:
            return
        
        path.append(node.val)
        if isLeaf(node) and sum(path) == target:
            result.append(path[:])
        
        bfs(node.left, target, path, result)
        bfs(node.right, target, path, result)

        path.pop()
    
    results = []
    bfs(root, target, [], results)
    return results

def main() -> None:
    print("请用前序遍历输入节点值(空节点用'#'表示): ")
    print("例如:124##56###378###9#0##")
    print("Attention: 输入的节点值必须为整数且是0-9!")
    s = input()
    root, _ = createBiTree(s, 0)
    print("二叉树: ")
    preorder(root)
    target = int(input("\n输入目标和: "))
    results = check_path_sum(root, target)
    print("路径和为", target, "的路径有: ", results)


if __name__ == '__main__':
    main()


