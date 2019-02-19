#Author guo
#树 非线性数据结构
#二叉树 具有左子树右子树 两个子节点 叶子节点
#二叉搜索树 每个节点都不比它左子树任意元素小，而且不比它的右子树的任意元素大
#完全二叉树  除h层外其它各层都达到最多 就不能称作完全二叉树
#满二叉树 每一个结点都有
#平衡二叉树 AVL树 二叉排序树，左右两个子树高度差绝对值不超过1 左右两个数都是平衡二叉树
#字典套字典来存一个二叉树json格式的 面向对象也可以存
#left=i right=i+1 parent=(i-1)/2 存在数组中实现

class Node(object):
    """二叉树节点"""

    def __init__(self, elem=-1, lchild=None, rchild=None):
        self.elem = elem
        self.lchild = lchild
        self.rchild = rchild


class Tree(object):
    """二叉树"""

    def __init__(self, root=None):
        self.root = root

    def add(self, elem):
        """为树添加节点"""
        node = Node(elem)
        # 如果树是空的，则对根节点赋值
        if self.root == None:
            self.root = node
        else:
            queue = list()
            queue.append(self.root)
            while queue:
                # 弹出队列的第一个元素
                cur = queue.pop(0)
                if cur.lchild == None:
                    cur.lchild = node
                    return
                elif cur.rchild == None:
                    cur.rchild = node
                    return
                else:
                    # 如果左右子树都不为空，往判断列表加入子树，循环进行子树的判断
                    queue.append(cur.lchild)
                    queue.append(cur.rchild)

    def preorder(self, root):
        """递归实现先序遍历"""
        if root == None:
            return
        print(root.elem)
        self.preorder(root.lchild)
        self.preorder(root.rchild)

    def inorder(self, root):
        """递归实现中序遍历"""
        if root == None:
            return
        self.inorder(root.lchild)
        print(root.elem)
        self.inorder(root.rchild)

    def postorder(self, root):
        """递归实现后续遍历"""
        if root == None:
            return
        self.postorder(root.lchild)
        self.postorder(root.rchild)
        print(root.elem)

    def breadth_travel(self, root):
        """利用队列实现树的层次遍历"""
        if root == None:
            return
        queue = list()
        queue.append(root)
        while queue:
            node = queue.pop(0)
            print(node.elem)
            if node.lchild != None:
                queue.append(node.lchild)
            if node.rchild != None:
                queue.append(node.rchild)
