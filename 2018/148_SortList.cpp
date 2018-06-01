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
    ListNode* sortList(ListNode* head) {
    	if(!head || !head->next){return head;}
    	// 算链表长度
    	ListNode* p = head;
    	int length = 0;
    	while(p){
    		length++;
    		p = p->next;
    	}
    	return sort(head, length);
    }
    ListNode* sort(ListNode* head, int length){
    	if(length<=1){return head;}
    	ListNode node(0);
    	node.next = head;
    	ListNode* p = &node;
    	for(int i=0; i<length/2; i++){
    		p = p->next;
    	}
    	ListNode* second_half = p->next;
    	p->next = NULL;
    	ListNode* first_half = Solution::sort(node.next, length/2);
    	second_half = Solution::sort(second_half, length - length/2);
    	return Solution::mergeSortedList(first_half, second_half);
    }
    ListNode* mergeSortedList(ListNode* h1, ListNode* h2){
    	ListNode node(0);
    	ListNode* p = &node;
    	while(h1 && h2){
    		if(h1->val<h2->val){
    			p->next = h1;
    			h1 = h1->next;
    		}
    		else{
    			p->next = h2;
    			h2 = h2->next;
    		}
    		p = p->next;
    	}
    	if(h1 || h2){
    		ListNode* h = h1 ? h1 : h2;
    		p->next = h;
    	}
    	return node.next;
    }
};