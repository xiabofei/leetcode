#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head)
    {
    	if (!head) return head;
  		ListNode dummpy(head->val+1);
  		dummpy.next = head;
  		ListNode *pre = &dummpy;
  		ListNode *p = head;
  		while (p)
  		{
  			if ( pre->val==p->val )
  			{
  				pre->next = p->next;
  				p = p->next;
  			}
  			else
  			{
  				pre = p;
  				p = p->next;
  			}
  		}	 
  		return dummpy.next;     
    }
};