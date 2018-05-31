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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m==n || !head){return head;}
    	ListNode before_head(0);
    	ListNode* p = &before_head;
    	before_head.next = head;
    	for(int i=0; i<m-1; i++){
    		p = p->next;
    	}
    	ListNode* curr = p->next;
    	for(int i=0; i<n-m; i++){
    		ListNode* tmp = curr->next;
    		curr->next = curr->next->next;
    		tmp->next = p->next;
    		p->next = tmp;
    	}
    	return before_head.next;
    }
};