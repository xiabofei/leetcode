#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
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

class Solution {
public:
	int diameterOfBinaryTree(TreeNode* root) {
		if(!root){return 0;}
		int diameter = 0;
		int left = depth(root->left, diameter);
		int right = depth(root->right, diameter);
		return max(left+right+1, diameter)-1;
	}
	int depth(TreeNode* p, int& diameter){
		if(p==NULL){return 0;}
		int left = depth(p->left, diameter);
		int right = depth(p->right, diameter);
		diameter = max(diameter, left+right+1);
		return max(left, right)+1;
	}
};
