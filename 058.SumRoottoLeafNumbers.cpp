#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int sumNumbers(TreeNode* root)
    {
    	int global = 0;
    	if (root) Solution::dfs(root, global, 0);
    	return global;
    }
    static void dfs(TreeNode *root , int& global, int tmp)
    {
    	if ( !root->left && !root->right )
    	{
    		tmp = tmp*10 + root->val;
    		global = global + tmp;
    		return;
    	}
    	if (root->left) Solution::dfs(root->left, global, tmp*10+root->val);
    	if (root->right) Solution::dfs(root->right, global, tmp*10+root->val);
    }
};