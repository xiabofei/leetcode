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

// http://www.cnblogs.com/grandyang/p/4567827.html
// 

class Solution {
public:
	int countNodes(TreeNode* root) {
		if(!root){return 0;}
		// 左子树深度
		int lh = 0;
		TreeNode* pleft = root;
		while(pleft){
			++lh;
			pleft = pleft->left;
		}
		// 右子树深度
		int rh = 0;
		TreeNode* pright = root;
		while(pright){
			++rh;
			pright = pright->right;
		}
		if(lh==rh){
			// 剪枝 : left most height 和 right most height 相等
			// 满二叉树
			return pow(2, lh)-1;
		}
		else{
			// 总能分解为满二叉树 再求解
			return countNodes(root->left) + countNodes(root->right) + 1;
		}
	}
};
