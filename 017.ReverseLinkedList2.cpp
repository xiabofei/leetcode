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
    ListNode* reverseBetween(ListNode* head, int m, int n)
    {
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	ListNode *pre = &dummpy;
    	ListNode *p = head;
    	for ( int i=0; i<m-1; ++i ) 
    	{
    		pre = p;
    		p = p->next;
    	}
    	for ( int i=0; i<n-m; ++i )
    	{
    		ListNode * tmp = p->next;
    		p->next = tmp->next;
    		tmp->next = pre->next;
    		pre->next = tmp;
    	}
    	return dummpy.next;
    }
};