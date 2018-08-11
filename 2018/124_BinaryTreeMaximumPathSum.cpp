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


// 分类讨论
// 最大值是否以当前node开始

class Solution {
public:
    int maxPathSum(TreeNode* root) {
    	if(!root){return 0;}
    	int ret = INT_MIN;
    	dfs(ret, 0, root);
    	return ret;
    }
    int dfs(int& ret, int pre, TreeNode* node){
    	if(!node){
    		ret = max(ret, pre);
    		return 0;
    	}
    	if(pre<=0){
    		pre = node->val;
    	}
    	else{
    		pre = pre + node->val;
    	}
    	int l = dfs(ret, pre, node->left);
    	int r = dfs(ret, pre, node->right);
    	ret = max(ret, node->val+max(l,0)+max(r,0));
    	return max(node->val+max(l,0), node->val+max(r,0));
    }
};