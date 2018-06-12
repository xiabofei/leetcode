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
    bool isSymmetric(TreeNode* root) {
    	if(!root){return true;}
    	if(!root->left && root->right){return false;}
    	if(root->left && !root->right){return false;}
    	root->right = Solution::invert(root->right);
    	return Solution::isSame(root->left, root->right);
    }
    bool isSame(TreeNode* p, TreeNode* q){
    	if(!p && !q){return true;}
    	if((!p && q) || (p && !q) || (p->val!=q->val)){return false;}
    	bool l = Solution::isSame(p->left, q->left);
    	if(!l){return false;}
    	bool r = Solution::isSame(p->right, q->right);
    	return l && r;
    }
    TreeNode* invert(TreeNode* root){
    	if(!root){return root;}
    	TreeNode* tmp = root->left;
    	root->left = Solution::invert(root->right);
    	root->right = Solution::invert(tmp);
    	return root;
    }
};