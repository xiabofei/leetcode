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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ret;
		Solution::inorder(root, ret);
		return ret;
	}
	void inorder(TreeNode* node, vector<int>& ret){
		if(!node){return;}
		if(node->left){
			Solution::inorder(node->left, ret);
		}
		ret.push_back(node->val);
		if(node->right){
			Solution::inorder(node->right, ret);
		}
	}
};
