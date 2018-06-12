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
    TreeNode* invertTree(TreeNode* root) {
    	if(!root){return root;}
    	TreeNode* tmp = root->left;
    	root->left = Solution::invertTree(root->right);
    	root->right = Solution::invertTree(tmp);
    	return root;
    }
};