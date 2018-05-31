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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head){return head;}
    	ListNode* headhead = new ListNode(0);
    	headhead->next = head;
    	ListNode* p1 = headhead;
    	ListNode* p2 = headhead;
    	while(p2->next){
    		if(p1->next->val!=p2->next->val){
    			if(p1->next==p2){
    				p1 = p1->next;
    			}
    			else{
    				p1->next = p2->next;
    			}
    		}
    		p2 = p2->next;
    	}
    	if(p1->next!=p2){
    		p1->next = NULL;
    	}
    	return headhead->next;
    }
};