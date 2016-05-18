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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	// pointer p1 move n steps ahead
    	ListNode *p1 = &dummpy;
    	for ( int i=0; i<n; ++i ) p1 = p1->next;
    	// two pointer move together
    	ListNode *p2 = &dummpy;
    	while ( p1 && p1->next )
    	{
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    	// remove the nth node
    	p2->next = p2->next ? p2->next->next : NULL;
    	return dummpy.next;
    }
};