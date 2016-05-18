#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
    	return Solution::merge(lists, 0, lists.size()-1);
    }
    static ListNode* merge(vector<ListNode*>& lists, int begin, int end)
    {
    	if ( begin>end ) return NULL;
    	if ( begin==end ) return lists[begin];
    	int mid = (begin+end)/2;
    	ListNode *l1 =  Solution::merge(lists, begin, mid);
    	ListNode *l2 =  Solution::merge(lists, mid+1, end);
    	return Solution::mergeTwo(l1, l2);
    }
    static ListNode* mergeTwo(ListNode *h1, ListNode *h2)
    {
    	ListNode dummpy(-1);
    	ListNode *p = &dummpy;
    	while ( h1 && h2 )
    	{
    		if ( h1->val<h2->val )
    		{
    			p->next = h1;
    			h1 = h1->next;
    		}
    		else
    		{
    			p->next = h2;
    			h2 = h2->next;
    		}
    		p = p->next;
    	}
    	p->next = h1 ? h1 : h2;
    	return dummpy.next;
    }
};