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
    	ListNode* p1 = head;
    	ListNode* p2 = head;
    	while(p2){
    		if(p2->val==p1->val){
    			p2 = p2->next;
    		}
    		else{
    			p1->next = p2;
    			p1 = p2;
    		}
    	}
    	p1->next = p2;
    	return headhead->next;
    }
};