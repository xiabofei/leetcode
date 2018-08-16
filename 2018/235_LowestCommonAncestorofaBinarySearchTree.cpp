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

// BST的LCA问题 : 核心是比较大小
// 都比root小 就在root->left侧
// 都比root大 就在root->right侧
// 一个比root大 一个比root小 就返回root 
// root一定是最近公共根节点


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(!root){return NULL;}
    	if(root->val > p->val && root->val > q->val){
    		return lowestCommonAncestor(root->left, p, q);
    	}
    	if(root->val < p->val && root->val < q->val){
    		return lowestCommonAncestor(root->right, p, q);
    	}
    	return root;
    }
};