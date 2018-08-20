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


// 返回的是from left 或 from right最大的
// 更新的时候考虑curr node


class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
    	int ret = 0;
    	if(!root){return ret;}
    	Solution::path(root, ret);
    	return ret;
    }
    int path(TreeNode* root, int& longest){
    	// 从左节点开始的最长路径
    	int left = root->left ? Solution::path(root->left, longest) : 0;
    	// 从右节点开始的最长路径
    	int right = root->right ? Solution::path(root->right, longest) : 0;
    	// 从左节点出发 且 包含当前节点的最长路径
    	int curr_left = root->left && root->val==root->left->val ? left+1 : 0;
    	// 从右节点出发 且 包含当前节点的最长路径
    	int curr_right = root->right && root->val==root->right->val ? right+1 : 0;
    	// 更新最长的路径
    	longest = max(longest, curr_left+curr_right);
    	// 返回包含当前节点的最长路径
    	return max(curr_left, curr_right);
    }
};