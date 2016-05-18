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
    int minDepth(TreeNode* root)
    {
  		if (!root) return 0;
  		if ( !root->left && !root->right ) return 1;
  		int l = INT_MAX, r = INT_MAX;
  		if ( root->left ) l = Solution::minDepth(root->left);
  		if ( root->right ) r = Solution::minDepth(root->right);
  		return min(l,r)+1;
    }
};