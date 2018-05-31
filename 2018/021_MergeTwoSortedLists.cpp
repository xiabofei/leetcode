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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode* head = new ListNode(0);
    	ListNode* curr = head;
    	while(l1 && l2){
    		if(l1->val<l2->val){
    			curr->next = l1;
    			l1 = l1->next;
    		}
    		else{
    			curr->next = l2;
    			l2 = l2->next;
    		}
    		// 别忘了迭代curr指针
    		curr = curr->next;
    	}
    	if(l1||l2){
    		curr->next = l1 ? l1 : l2;
    	}
    	return head->next;
    }
};