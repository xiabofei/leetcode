#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
1 7 4 5 2 这种的显然是7和2位置错了 第一次遇到pre->val > curr->val的时候获得n1为7
第二次获得n2为2
1 7 4 这种显然是7和4位置错了 第一次遇到
*/
class Solution {
public:
    void recoverTree(TreeNode* root)
    {
    	stack<TreeNode*> sta;
    	TreeNode *pre = new TreeNode(INT_MIN);
    	TreeNode *curr = root;
    	TreeNode *n1=NULL, *n2=NULL;
    	while ( !sta.empty() || curr )
    	{
    		if ( curr )
    		{
    			sta.push(curr);
    			curr = curr->left;
    		}
    		else
    		{
    			curr = sta.top(); sta.pop();
    			if ( pre->val > curr->val )
    			{
    				if ( !n1 )
    				{
    					n1 = pre;
    					n2 = curr;
    				}
    				else
    				{
    					n2 = curr;
    					break;
    				}
    			}
    			pre = curr;
    			curr = curr->right;
    		}
    	}
    	if (n1) swap(n1->val, n2->val);
    }
};