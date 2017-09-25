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
    vector<int> inorderTraversal(TreeNode* root) {
  		vector<int> ret;
  		if (!root) return ret;
  		stack<TreeNode*> sta;
  		TreeNode *curr = root;
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
  				ret.push_back(curr->val);
  				curr = curr->right;
  			}
  		}
  		return ret;
    }
};