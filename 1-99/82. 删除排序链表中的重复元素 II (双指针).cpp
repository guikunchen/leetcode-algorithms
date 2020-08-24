#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/

/**
输入: 1->2->3->3->4->4->5
输出: 1->2->5
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode headNode(0), *current = &headNode;
        headNode.next = head;

        while (current->next && current->next->next){// 双指针！！！
            if(current->next->val == current->next->next->val){
                ListNode *tmp = current->next->next->next;
                while(tmp && tmp->val == current->next->val){// 可能不止两个元素重复
                    tmp = tmp->next;
                }
                current->next = tmp;
            }
            else{
                current = current->next;
            }
        }
        return headNode.next;
    }
};
// 上面这个代码处理[1,2,3,3,4,4,5,3]得到的结果是[1,2,5,3]，不过没有进行内存管理
// 题目给的是排序链表，排序链表的特点是不断增大，后面的元素不可能和前面的相同。



// 下面这个代码可以处理[1,2,3,3,4,4,5,3]
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> hashMap;
        while(head){
            if(hashMap.count(head->val)){
                hashMap[head->val] += 1;
            }
            else{
                hashMap[head->val] = 1;
            }
        }
        ListNode headNode(0), *p = &headNode;
        while(head){
            if(hashMap.count(head->val) && hashMap[head->val] > 1){
                tmp = head;
                head = head->next;
                delete tmp;
            }
            else{
                p->next = head;
                head = head->next;
                p->next = NULL;
            }
        }
        return headNode.next;
    }
};