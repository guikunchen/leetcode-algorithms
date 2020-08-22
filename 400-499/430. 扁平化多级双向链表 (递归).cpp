// https://leetcode-cn.com/problems/flatten-a-multilevel-doubly-linked-list/
/*多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。

给你位于列表第一级的头节点，请你扁平化列表，使所有结点出现在单级双链表中。*/
class Solution {
public:// 可以递归也可以用栈模拟递归
    Node* flatten(Node* head) {
        if(head == nullptr) return head;
        Node preHead(0, nullptr, head, nullptr);

        flattenDFS(&preHead, head);
        preHead.next->prev = nullptr;
        return preHead.next;
    }

    Node* flattenDFS(Node* prev, Node* cur) {
        if(cur == nullptr) return prev;
        prev->next = cur;
        cur->prev = prev;

        Node *tmpNext = cur->next;
        Node *tail = flattenDFS(cur, cur->child);
        cur->child = nullptr;

        return flattenDFS(tail, tmpNext);
    }


    Node* flatten(Node* head) {
        stack<Node*> s;
        Node *pre=NULL;
        if(head)//先判断头结点是否为空
            s.push(head);
        while (!s.empty())
        {
            Node *t = s.top();
            s.pop();
            if(t->next)//注意：后继节点优先入栈
            {
                s.push(t->next);
            }
            if(t->child)
            {
                s.push(t->child);
                t->child = NULL;//将该节点的child指针清空
            }
            if(pre)
            {
                pre->next = t;
                t->prev = pre;
            }
            pre = t;//pre指向刚出栈的节点
        }
        return head;
    }

};