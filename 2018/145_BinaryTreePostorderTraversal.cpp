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
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		Solution::traversal(root, ret);
		return ret;
	}
	void traversal(TreeNode* node, vector<int>& ret){
		if(!node){return;}
		if(node->left){Solution::traversal(node->left, ret);};
		if(node->right){Solution::traversal(node->right, ret);};
		ret.push_back(node->val);
	}
}