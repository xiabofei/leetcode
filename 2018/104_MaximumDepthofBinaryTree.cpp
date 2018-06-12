#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
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
    int maxDepth(TreeNode* root) {
    	if(!root){return 0;}
    	if(!root->left && !root->right){return 1;};
    	int l_depth = Solution::maxDepth(root->left);
    	int r_depth = Solution::maxDepth(root->right);
    	return max(l_depth, r_depth)+1;
    }
};