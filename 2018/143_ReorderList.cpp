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
    void reorderList(ListNode* head) {
    	if(!head){return;}
    	ListNode before_head(0);
    	before_head.next = head;

    	// 第一个pass求链表长度
    	ListNode* p = head;
    	int length = 0;
    	while(p){
    		length++;
    		p = p->next;
    	}
    	if(length==1){return;}

    	// 第二个pass拆分链表
    	p = &before_head;
    	ListNode second_half_node(0);
    	ListNode* p_second_half = &second_half_node;
    	for(int i = 0; i<(length+1)/2; i++){
    		p = p->next;
    	}
    	p_second_half->next = p->next;
    	p->next = NULL;

    	// 第三个pass翻转后半部分链表
    	ListNode* curr = p_second_half->next;
    	while(curr->next){
    		ListNode* tmp = curr->next;
    		curr->next = curr->next->next;
    		tmp->next = p_second_half->next;
    		p_second_half->next = tmp;
    	}

    	// 第四个pass merge两个链表
    	p = before_head.next;
    	ListNode* p1= second_half_node.next;
    	while(p && p1){
    		ListNode* tmp = p->next;
    		p->next = p1;
    		p1 = p1->next;
    		p->next->next = tmp;
    		p = tmp;
    	}
    	return;
    }
};