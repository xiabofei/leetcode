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
    bool hasCycle(ListNode *head) {
    	if(!head){return false;}
    	ListNode before_head(0);
    	before_head.next = head;

    	ListNode* p1 = &before_head;
    	ListNode* p2 = &before_head;
        
        while(p2 && p2->next){
        	p2 = p2->next->next;
        	p1 = p1->next;
        	if(p2==p1){return true;}
        }
        return false;
    }
};