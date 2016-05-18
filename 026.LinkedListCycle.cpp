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
    bool hasCycle(ListNode *head)
    {
    	if ( !head ) return false;
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	ListNode *p1 = &dummpy;
    	ListNode *p2 = &dummpy;
    	while ( p2 )
    	{
    		if ( p2->next ) 
    		{
    			p2 = p2->next->next;
    		}
    		else
    		{
    			return false;
    		}
    		p1 = p1->next;
    		if ( p1==p2 ) return true;
    	}
    	return false;
    }
};