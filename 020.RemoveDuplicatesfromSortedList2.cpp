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
    ListNode* deleteDuplicates(ListNode* head)
    {
    	if (!head) return head;
    	ListNode dummpy(head->val+1);
    	dummpy.next = head;
    	ListNode *pre = &dummpy;
    	ListNode *p = head;
    	while ( p && p->next )
    	{
    		if ( p->val!=p->next->val )
    		{
    			pre = p;
    			p = p->next;
    		}
    		else
    		{
    			while ( p && p->next )
    			{
    				if ( p->val!=p->next->val ) break;
    				p = p->next;
    			}
    			pre->next = p->next;
    			p = p->next;
    		}
    	}
    	return dummpy.next;
    }
};