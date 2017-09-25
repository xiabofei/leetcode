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
    ListNode *detectCycle(ListNode *head)
    {
    	if ( !head ) return head;
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	ListNode *p1 = &dummpy; // if here p1=&dummpy then in line 37 must p1=&dummpy
    	ListNode *p2 = &dummpy;
    	// find first meeting point
    	while ( true )
    	{
    		if ( p2 && p2->next )
    		{
    			p2 = p2->next->next;
    		}
    		else
    		{
    			return NULL;
    		}
    		p1 = p1->next;
    		if ( p2==p1 ) break;
    	}
    	// p1 from the head and p2 from the meeting point
    	p1 = &dummpy; // not p1=head but p1=&dummpy
    	while ( p1!=p2 )
    	{
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    	return p1;
    }
};