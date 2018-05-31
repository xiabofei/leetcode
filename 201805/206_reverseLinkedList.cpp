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
    ListNode* reverseList(ListNode* head) {
    	ListNode* headhead = new ListNode(0);
    	headhead->next = head;
    	ListNode* p = head;
    	while(p){
    		ListNode* tmp = p->next;
    		if(!tmp){break;}
    		p->next = tmp->next;
    		tmp->next = headhead->next;
    		headhead->next = tmp;
    	}
    	return headhead->next;
    }
};