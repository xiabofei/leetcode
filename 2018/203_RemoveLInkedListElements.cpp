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
    ListNode* removeElements(ListNode* head, int val) {
    	ListNode node(0);
    	node.next = head;
    	ListNode* p = &node;
    	while(p && p->next){
    		if(p->next->val==val){
    			p->next = p->next->next;
    		}
    		else{
    			p = p->next;
    		}
    	}
    	return node.next;
    }
};