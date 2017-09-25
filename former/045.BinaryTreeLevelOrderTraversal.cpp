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
    vector<vector<int> > levelOrder(TreeNode* root)
    {
    	vector<vector<int> > ret;
    	if (!root) return ret;
    	queue<TreeNode*> curr, next;
    	curr.push(root);
    	while ( !curr.empty() )
    	{
    		vector<int> level;
    		while ( !curr.empty() )
    		{
    			TreeNode *tmp = curr.front(); curr.pop();
    			level.push_back(tmp->val);
    			if ( tmp->left ) next.push(tmp->left);
    			if ( tmp->right ) next.push(tmp->right);
    		}
    		ret.push_back(level);
    		swap(curr, next);
    	}
    	return ret;
    }
};