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
    void flatten(TreeNode* root)
    {
    	if (!root) return;
    	TreeNode *pre = new TreeNode(0);
    	stack<TreeNode*> sta;
    	sta.push(root);
    	while ( !sta.empty() )
    	{
    		TreeNode *curr = sta.top(); sta.pop();
    		pre->right = curr;
    		pre->left = NULL;
    		if (curr->right) sta.push(curr->right);
    		if (curr->left) sta.push(curr->left);
    		pre = curr;
    	}
    }
};