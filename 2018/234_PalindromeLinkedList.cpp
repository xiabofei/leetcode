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
    bool isPalindrome(ListNode* head) {
    	if(!head || !head->next){return true;}

    	// 求list长度
    	ListNode node(0);
    	node.next = head;
    	ListNode* p = head;
    	int length = 0;
    	while(p){
    		length++;
    		p = p->next;
    	}

    	// 从中间截断list 翻转后部分链表
    	p = &node;
    	for(int i=0; i<(length+1)/2; i++){
    		p = p->next;
    	}
    	ListNode node2(0);
    	node2.next = p->next;
    	p->next = NULL;
    	ListNode* p2 = &node2;
    	ListNode* curr = node2.next;
    	while(curr->next){
    		ListNode* tmp = curr->next;
    		curr->next = curr->next->next;
    		tmp->next = p2->next;
    		p2->next = tmp;
    	}

    	// 比较是否是回文(后半部分比前半部分短)
    	p = node.next;
    	p2 = node2.next;
    	while(p2){
    		if(p->val!=p2->val){
    			return false;
    		}
    		p2 = p2->next;
    		p = p->next;
    	}
    	return true;
    }
};