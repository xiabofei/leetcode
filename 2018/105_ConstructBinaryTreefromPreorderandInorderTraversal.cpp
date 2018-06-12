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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    	return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(
    	vector<int>& preorder, int beginP, int endP, 
    	vector<int>& inorder, int beginI, int endI){
    	if(beginP>endP || beginI>endI){return NULL;}
    	// 在preorder中确定root位置
    	TreeNode* root = new TreeNode(preorder[beginP]);
    	// 在inorder中找到root的位置
    	int root_pos = beginI;
    	while(root_pos<=endI && inorder[root_pos]!=preorder[beginP]){root_pos++;}
    	// left长度
    	int left_len = root_pos - beginI;
    	// 递归生成树
    	root->left = build(preorder, beginP+1, beginP+left_len, inorder, beginI, root_pos-1);
    	root->right = build(preorder, beginP+left_len+1, endP, inorder, root_pos+1, endI);
    	return root;
    }
};