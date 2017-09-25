#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* swapPairs(ListNode* head)
    {
    	if ( !head || !head->next ) return head;
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	ListNode *p = &dummpy;
    	while ( p && p->next && p->next->next )
    	{
    		ListNode *tmp = p->next->next;
    		p->next->next = tmp->next;
    		tmp->next = p->next;
    		p->next = tmp;
    		p = tmp->next;
    	}
    	return dummpy.next;
    }
};