#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
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
    bool isValidBST(TreeNode* root) {
    	if(!root){return true;}
    	return Solution::valid(root, LONG_MIN, LONG_MAX);
    }
    bool valid(TreeNode* root, long min_val, long max_val){
    	if(!root){return true;}
    	bool val = root->val > min_val && root->val < max_val;
    	if(!val){return false;}
    	bool l = Solution::valid(root->left, min_val, root->val);
    	if(!l){return false;}
    	bool r = Solution::valid(root->right, root->val, max_val);
    	return val && l && r;
    }
};