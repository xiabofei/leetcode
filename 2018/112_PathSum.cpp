#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
    	if(!root){return false;}
    	if(!root->left && !root->right && root->val==sum){
    		return true;
    	}
    	bool l = Solution::hasPathSum(root->left, sum - root->val);
    	if(l){return true;}
    	bool r = Solution::hasPathSum(root->right, sum - root->val);
    	return r;
    }
};