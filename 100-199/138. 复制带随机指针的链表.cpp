// https://leetcode-cn.com/problems/copy-list-with-random-pointer/

//第一步：在每个节点右侧插入一个新节点
//第二部：连接新节点的random指针
//第三步：断开，（奇数偶数结点分开）

class Solution {
public:
//深度拷贝：构造生成一个完全新的链表，即使将原链表毁坏，新链表可独立使用
    Node* copyRandomList(Node* head) 
    {
        //O(1)空间的迭代
        Node* ptr=head;
        Node* medium=NULL;
        if(head == NULL)
            return NULL;
        //创建相邻结点
        while(ptr != NULL)
        {
            medium=ptr->next;
            ptr->next=new Node(ptr->val);//ptr后创建新结点
            ptr->next->next=medium;
            ptr=ptr->next->next;
        }
        //遍历新链表，修改新结点的random指针
        ptr=head;
        while(ptr != NULL)
        {
            if(ptr->random != NULL)
            {
                ptr->next->random=ptr->random->next;
            }
            else
            {
                ptr->next->random=NULL;
            }
            ptr=ptr->next->next;
        }
        //修改链表结构(这个地方没有学懂，抄的官方题解)
        Node* ptr_old_list=head;
        Node* ptr_new_list=head->next;
        Node *result=head->next;
        while(ptr_old_list != NULL)
        {
            ptr_old_list->next=ptr_old_list->next->next;
            if(ptr_new_list->next != NULL)
                ptr_new_list->next=ptr_new_list->next->next;
            else
                ptr_new_list->next=NULL;
            ptr_old_list=ptr_old_list->next;
            ptr_new_list=ptr_new_list->next;
        }
        return result;
    } 
};