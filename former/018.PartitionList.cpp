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
    ListNode* partition(ListNode* head, int x)
    {
    	ListNode dummpy1(-1);
 		ListNode dummpy2(-2);
  		ListNode *less = &dummpy1;
  		ListNode *larger = &dummpy2;
  		ListNode *p = head;
  		while (p)
  		{
  			if ( p->val<x )
  			{
  				less->next = p;
  				p = p->next;
  				less = less->next;
  				less->next = NULL;
  			}
  			else
  			{
  				larger->next = p;
  				p = p->next;
  				larger = larger->next;
  				larger->next = NULL;
  			}
  		}
  		less->next = dummpy2.next;
  		return dummpy1.next;
    }
};