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
    ListNode* oddEvenList(ListNode* head) {
    	if(!head || !head->next){return head;}

    	ListNode odd_node(0);
    	ListNode* p_odd = &odd_node;
    	ListNode even_node(0);
    	ListNode* p_even = &even_node;
        
    	ListNode* p = head;
    	int sign = 1;
        while(p){
        	if(sign!=0){
        		p_odd->next = p;
        		p_odd = p_odd->next;
        	}
        	else{
        		p_even->next = p;
        		p_even = p_even->next;
        	}
        	p = p->next;
        	sign = 1 - sign%2;
        }
        p_even->next = NULL;
        p_odd->next = even_node.next;
        return odd_node.next;
    }
};