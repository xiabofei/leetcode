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
    int maxPathSum(TreeNode* root)
    {
    	int global = INT_MIN;
    	Solution::sum(root, global);
    	return global;
    }
    static int sum(TreeNode *root, int& global)
    {
    	if (!root) return 0;
    	int l = Solution::sum(root->left, global);
    	int r = Solution::sum(root->right, global);
    	global = max( global, root->val+(l>0?l:0)+(r>0?r:0) ); // 贪心法
    	return max(root->val, root->val+max(l,r)); // 不能分叉
    }
};