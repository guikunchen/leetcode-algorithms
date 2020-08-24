#include<iostream>
#include<vector>
#include<set>
using namespace std;
// https://leetcode-cn.com/problems/sort-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	// 看到空间1就不能用递归
	// 看到时间nlogn就想到二分，然后再想到归并排序
	// 归并排序的迭代方式就是，step从1开始每次乘2，每趟对step进行排序。
	ListNode* merge(ListNode* left, ListNode* right){// 合并两个有序链表
		ListNode preHead(0);
		preHead.next = left;
		ListNode *p = &preHead;
		while(p->next != nullptr && right != nullptr){
			int rv = right->val;
			while(rv > p->next->val){
				if(p->next->next == nullptr){
					p->next->next = right;
					return preHead.next;
				}
				p = p->next;
			}
			ListNode *tmp = right;
			right = right->next;
			tmp->next = p->next;
			p->next = tmp;
		}
		return preHead.next;
	}

    ListNode* sortList(ListNode* head) {
    	int count = 0;
    	ListNode *cur = head;
    	while(cur != nullptr){
    		count++;
    		cur = cur->next;
    	}

    	ListNode preHead(0);
		preHead.next = head;

		for(int step = 1; step < count; step <<= 1){
			ListNode *pre = &preHead;
			cur = pre->next;

			// 分为三个部分，前两个部分进行归并排序
			while(cur != nullptr){
				ListNode *first = cur;
				for(int i = 1; i < step && cur != nullptr; i++){
					cur = cur->next;
				}
				if(cur == nullptr){// 第一个部分都凑不完
					break;
				}

				ListNode *second = cur->next;
				cur->next = nullptr;// 断开第一部分
				cur = second;
				for(int i = 1; i < step && cur != nullptr; i++){
					cur = cur->next;
				}

				ListNode *remain = nullptr;
				if(cur != nullptr){// 切割第二部分和第三部分
					remain = cur->next;
					cur->next = nullptr;
				}
				cur = remain;// 进行下次同样step的归并排序

				ListNode *tmp = merge(first, second);
				pre->next = tmp;
				while(pre->next != nullptr){
					pre = pre->next;
				}
				pre->next = remain;
			}
		}

		return preHead.next;
    }
};