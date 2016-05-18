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
    bool isValidBST(TreeNode* root)
    {
    	return Solution::valid(root, LONG_MIN, LONG_MAX);
    }
    static bool valid(TreeNode* root, int mini, int maxi )
    {
    	if ( !root ) return true;
    	return root->val>mini && 
    		   root->val<maxi && 
    	       Solution::valid(root->left, mini, root->val) && 
    	       Solution::valid(root->right, root->val, maxi);
    }
};