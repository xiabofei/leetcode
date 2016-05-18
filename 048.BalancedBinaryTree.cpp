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

class Solution {
public:
    bool isBalanced(TreeNode* root)
    {
    	if (!root) return true;
    	if ( abs(Solution::height(root->left) - Solution::height(root->right))<2 )
    	{
    		return Solution::isBalanced(root->left) && Solution::isBalanced(root->right);
    	}
    	else
    	{
    		return false;
    	}    
    }
    static int height(TreeNode *root)
    {
    	if (!root) return 0;
    	return max(Solution::height(root->left), Solution::height(root->right))+1;
    }
};