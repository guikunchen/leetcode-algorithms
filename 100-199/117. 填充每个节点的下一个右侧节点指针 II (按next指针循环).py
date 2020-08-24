# https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
#给定一个二叉树

# struct Node {
#   int val;
#   Node *left;
#   Node *right;
#   Node *next;
# }
# 填充它的每个 next 指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将 next 指针设置为 NULL。
# 初始状态下，所有 next 指针都被设置为 NULL。

# 进阶：

# 你只能使用常量级额外空间。
# 使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。 
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head = root
        while head:#当前层的头节点
            cur = head #当前层处理节点
            pre = head = None#初始化下一层头节点和前置节点
            while cur:
                if cur.left:
                    if not pre:#若尚未找到下一层前置节点，则同步更新下一层头节点和前置节点
                        pre = head =cur.left
                    else:#已找到下一层前置节点，则将前置节点指向当前子节点，并前移pre
                        pre.next = cur.left
                        pre = pre.next
                if cur.right:
                    if not pre:
                        pre = head = cur.right
                    else:
                        pre.next = cur.right
                        pre = pre.next
                cur = cur.next
        return root