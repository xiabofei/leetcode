#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    static TreeNode* sortedListToBST(ListNode* head)
    {
    	if ( !head ) return NULL;
    	if ( !head->next ) return new TreeNode(head->val);
    	ListNode *p1 = head;
    	ListNode *pre = p1;
    	ListNode *p2 = head;
    	while ( p2 && p2->next )
    	{
    		pre = p1;
    		p1 = p1->next;
    		p2 = p2->next->next;
    	}
    	TreeNode *root = new TreeNode(p1->val);
    	pre->next = NULL;
    	root->left = Solution::sortedListToBST(head);
    	root->right = Solution::sortedListToBST(p1->next);
    	return root;
    }
};