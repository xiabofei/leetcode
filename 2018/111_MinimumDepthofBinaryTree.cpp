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
    int minDepth(TreeNode* root) {
    	if(!root){return 0;}
    	if(root->left && !root->right){return Solution::minDepth(root->left)+1;}
    	if(!root->left && root->right){return Solution::minDepth(root->right)+1;}
    	return min(Solution::minDepth(root->left), Solution::minDepth(root->right))+1;
    }
};