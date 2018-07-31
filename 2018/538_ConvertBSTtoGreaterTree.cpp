#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// https://blog.csdn.net/mrbcy/article/details/64440395
// 后序遍历 + 全局累加
// 用sum累加所有后序遍历先看到的点的和
// 非常自然的思路

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
    	int sum = 0;
    	convert(root, sum);
    	return root;
    }
    void convert(TreeNode* root, int& sum){
    	if(!root){return;}
    	convert(root->right, sum);
    	root->val += sum; 
    	sum = root->val;
    	convert(root->left, sum);
    }
};
