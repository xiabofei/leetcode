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
    ListNode* swapPairs(ListNode* head) {
    	ListNode* headhead = new ListNode(0);
    	headhead->next = head;
    	ListNode* p1 = headhead;
    	ListNode* p2 = headhead; 
    	while(p2 && p2->next){
    	    p2 = p2->next->next;
    	    if(!p2){break;}
    		ListNode* tmp = p1->next;
    		p1->next->next = p2->next;
    		p2->next = p1->next;
    		p1->next = p2;
    		p1 = tmp;
    		p2 = tmp;
    	}
    	return headhead->next;
    }
};