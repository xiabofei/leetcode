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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	return build(inorder, 0, inorder.size()-1, postorder, 0, inorder.size()-1);
    }
    TreeNode* build(
    	vector<int>& I, int beginI, int endI, 
    	vector<int>& P, int beginP, int endP){
    	if(beginI>endI || beginP>endP){return NULL;}
    	// postorder最后元素根节点
    	TreeNode* root = new TreeNode(P[endP]);
    	// inorder中找到根节点位置
    	int root_pos = beginI;
    	while(root_pos<=endI && I[root_pos]!=P[endP]){root_pos++;}
    	// 在postorder中摘出left/right nodes
    	int left_end = beginP + root_pos - beginI - 1;
    	// 递归生成树
    	root->left = build(I, beginI, root_pos-1, P, beginP, left_end);
    	root->right = build(I, root_pos+1, endI, P, left_end+1, endP-1);
    	return root;
    }
};