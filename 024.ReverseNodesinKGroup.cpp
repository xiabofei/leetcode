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
    static ListNode* reverseKGroup(ListNode* head, int k)
    {
    	if ( !head || !head->next || k<2 ) return head;
    	ListNode dummpy(-1);
    	dummpy.next = head;
    	ListNode *p = &dummpy;
    	ListNode *pre = &dummpy;
    	while (p)
    	{
    		// check if contain k more nodes
    		for ( int i=0; i<k && p; ++i ) p = p->next;
    		if (!p) break;
    		// reverse k nodes
    		ListNode *curr = pre->next;
    		for ( int i=0; i<k-1; ++i )
    		{
    			ListNode *tmp = curr->next;
    			curr->next = tmp->next;
    			tmp->next = pre->next;
    			pre->next = tmp;
    		}
    		pre = curr;
    		p = curr;
    	}
    	return dummpy.next;
    }
};
int main(int argc, char const *argv[])
{
	ListNode n1(1);
	ListNode n2(2);
	n1.next = &n2;
	Solution::reverseKGroup(&n1, 3);
	return 0;
}