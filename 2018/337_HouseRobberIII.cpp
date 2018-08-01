#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 基本思路 dfs 一个节点纳入sum或不纳入sum
// 保存中间结果

class Solution {
public:
	// 当tree node可用时 node以下最大的sum
	unordered_map<TreeNode*, int> used;
	// 当tree node不可用时 node以下最大的sum
	unordered_map<TreeNode*, int> not_used;
	int rob(TreeNode* root){
		if(!root){return 0;}
		return max(help(root, true), help(root, false));
	}
	int help(TreeNode* node, const bool available){
		// help的返回值是 包含当前节点 或 不包含当前节点的最大值
		if(!node){return 0;}
		int l=0;
		int r=0;
		// 尝试用当前节点 child节点不可用
		if(available){
			if(used.find(node)==used.end()){
				l = help(node->left, false);
				r = help(node->right, false);
				used[node] = node->val+l+r;
			}
			if(not_used.find(node)==not_used.end()){
				l = help(node->left, true);
				r = help(node->right, true);
				not_used[node] = l+r;
			}
			return max(used[node], not_used[node]);
		}
		else{
			// 尝试不用当前节点 child节点可用
			if(not_used.find(node)!=not_used.end()){
				return not_used[node];
			}
			l = help(node->left, true);
			r = help(node->right, true);
			not_used[node] = l+r;
			return l+r;
		}
	}
};