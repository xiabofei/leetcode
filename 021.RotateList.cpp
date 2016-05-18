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
    ListNode* rotateRight(ListNode* head, int k)
    {
     	if ( !head || !head->next ) return head;
     	int len = 0 ;
     	ListNode dummpy(-1);
     	dummpy.next = head;
     	ListNode *p = &dummpy;
     	// get length and tail node
     	while ( p && p->next ){
     		len++;
     		p = p->next;
     	}
     	k = k % len;
     	if (k==0) return head;
     	ListNode *tail = p;
     	// from left to right move to the chosen node
     	int left = len - k;
     	p = &dummpy;
     	for ( int i=0; i<left; ++i ) p = p->next;
     	ListNode *ret = p->next;
     	p->next = NULL;
     	tail->next = dummpy.next;
     	return ret;
    }
};