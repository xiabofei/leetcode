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
    vector<vector<int> > pathSum(TreeNode* root, int sum)
    {
    	vector<vector<int> > ret;
    	vector<int> tmp;
    	if (root) Solution::dfs(root, sum, tmp, ret, 0);
    	return ret;
    }
    static void dfs(TreeNode *root, int sum, 
    	vector<int>& tmp, vector<vector<int> >& ret, int presum)
    {
    	if ( !root->left && !root->right )
    	{	
    		if ( presum+root->val == sum )
    		{
    			tmp.push_back(root->val);
    			ret.push_back(tmp);
    			tmp.pop_back();
    		}
    		return;
    	}
    	tmp.push_back(root->val);
    	if ( root->left ) Solution::dfs(root->left, sum, tmp, ret, presum+root->val);
    	if ( root->right ) Solution::dfs(root->right, sum, tmp, ret, presum+root->val);
    	tmp.pop_back();
    }
};