#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
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
    int sumOfLeftLeaves(TreeNode* root) {
    	int ret = 0;
    	if(!root){return ret;}
    	Solution::calculate(root->left, ret, true);
    	Solution::calculate(root->right, ret, false);
    	return ret;
    }
    void calculate(TreeNode* root, int& sum, bool left){
    	if(!root){return;}
    	if(!root->left && !root->right && left){
    		sum += root->val;
    		return;
    	}
    	if(root->left){Solution::calculate(root->left, sum, true);}
    	if(root->right){Solution::calculate(root->right, sum, false);}
    }
};