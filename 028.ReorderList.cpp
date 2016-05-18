#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    void reorderList(ListNode* head)
    {
    	if ( !head || !head->next ) return;
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	// step 1 find median node
    	ListNode *p1 = &dummpy;
    	ListNode *p2 = &dummpy;
    	while ( true )
    	{
    		p1 = p1->next;
    		p2 = p2->next;
    		if ( p2 && p2->next )
    		{
    			p2 = p2->next;
    		}
    		else
    		{
    			break;
    		}
    	}
    	// step 2 reverse the second half list
    	p2 = p1->next;
    	p1->next = NULL;
    	ListNode dummpy2(-1);
    	dummpy2.next = p2;
    	p2 = &dummpy2;
    	ListNode *curr = dummpy2.next;
    	while ( curr && curr->next )
    	{
    		ListNode *tmp = curr->next;
    		curr->next = tmp->next;
    		tmp->next = p2->next;
    		p2->next = tmp;
    	}
    	// step 3 merge two list
    	p1 = dummpy.next;
    	p2 = dummpy2.next;
    	while ( p1 && p2 )
    	{
    		ListNode *tmp = p1->next;
    		p1->next = p2;
    		p2 = p2->next;
    		p1->next->next = tmp;
    		p1 = tmp;
    	}
    	return;
    }
};