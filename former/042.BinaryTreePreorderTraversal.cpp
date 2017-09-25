#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	/*
    vector<int> preorderTraversal(TreeNode* root)
    {
    	vector<int> ret;
    	if ( !root ) return ret;
    	stack<TreeNode*> sta;
    	sta.push(root);
    	while ( !sta.empty() )
    	{
    		TreeNode *tmp = sta.top();
    		sta.pop();
    		ret.push_back(tmp->val);
    		if (tmp->right) sta.push(tmp->right);
    		if (tmp->left) sta.push(tmp->left);
    	}
    	return ret;
    }
    */
    vector<int> preorderTraversal(TreeNode* root)
    {
    	vector<int> ret;
    	Solution::traversal(root, ret);
    	return ret;
    }
    static void traversal(TreeNode *root, vector<int>& ret)
    {
    	if ( !root ) return;
    	ret.push_back(root->val);
    	if ( root->left ) Solution::traversal(root->left, ret);
    	if ( root->right ) Solution::traversal(root->right, ret);
    	return;
    }
};