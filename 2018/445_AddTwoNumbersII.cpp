#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(!l1 || !l2){return l1 ? l1 : l2;}
        // 求出两个链表的长度
    	int len1 = 0;
    	int len2 = 0;
    	ListNode* p = l1;
    	while(p){len1++; p=p->next;}
    	p = l2;
    	while(p){len2++; p=p->next;}
    	// 把多出来的高位数据先加到新的链表中
    	ListNode head(0);
    	if(len1>len2){
    		for(int i=0; i<(len1-len2); i++){
    			ListNode* tmp = head.next;
    			head.next = new ListNode(l1->val);
    			head.next->next = tmp;
    			l1 = l1->next;
    		}
    	}
    	if(len1<len2){
    		for(int i=0; i<(len2-len1); i++){
    			ListNode* tmp = head.next;
    			head.next = new ListNode(l2->val);
    			head.next->next = tmp;
    			l2 = l2->next;
    		}
    	}
    	// 执行各个位置的add操作(不用管carry)
    	while(l1){
    		ListNode* tmp = head.next;
    		head.next = new ListNode(l1->val + l2->val);
    		head.next->next = tmp;
    		l1 = l1->next;
    		l2 = l2->next;
    	}

    	// 执行往前进位操作
    	p = &head; 
    	int carry = 0;
    	int digit = 0;
    	while(p->next){
    		digit = (carry+p->next->val)%10;
    		carry = (carry+p->next->val)/10;
    		p->next->val = digit;
    		p = p->next;
    	}
    	if(carry>0){
    		p->next = new ListNode(carry);
    	}

    	// 翻转链表
    	p = &head;
    	ListNode* curr = head.next;
    	while(curr->next){
    		ListNode* tmp = curr->next;
    		curr->next = curr->next->next;
    		tmp->next = p->next;
    		p->next = tmp;
    	}
    	return head.next;
    }
};