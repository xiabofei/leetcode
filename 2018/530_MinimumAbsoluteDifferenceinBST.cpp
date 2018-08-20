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

// BST先想到中序遍历有序
// 最小值肯定在相邻的节点产生
// 有一个点 不仅ret需要传引用
// pre也需要传引用保持

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
    	int ret = INT_MAX;
    	int pre = INT_MAX;
    	inorder(root, ret, pre);
    	return ret;
    }
    void inorder(TreeNode* root, int&ret, int& pre){
    	if(!root){return;}
    	inorder(root->left, ret, pre);
    	ret = min(ret, abs(pre - root->val));
    	pre = root->val;
    	inorder(root->right, ret, pre);
    }
};
