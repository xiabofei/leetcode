#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>


using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历BST 按由小到大顺序 获得kth smallest

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
    	int ret = 0;
    	int cnt = 0;
    	inorder(root, ret, cnt, k);
    	return ret;
    }
    void inorder(TreeNode* root, int& ret, int& cnt, const int k){
    	if(!root){return;}
    	if(cnt==k){
    		ret = root->val;
    		return;
    	}
    	inorder(root->left, ret, cnt, k);
    	++cnt;
    	if(cnt==k){
    		ret = root->val;
    		return;
    	}
    	inorder(root->right, ret, cnt, k);
    }
};