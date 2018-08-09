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


// 利用same tree的思想
// 对tree进行 root - left - right 和 root - right - left两种遍历方式
// 两种遍历方式满足same tree则符合条件

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return symmetric(root, root);
    }
    bool symmetric(TreeNode* r1, TreeNode* r2){
        if(!r1 && !r2){return true;}
        if(!r1 && r2){return false;}
        if(r1 && !r2){return false;}
        if(r1->val!=r2->val){return false;}
        bool sym1 = symmetric(r1->left, r2->right);
        if(!sym1){return false;}
        bool sym2 = symmetric(r1->right, r2->left);
        return sym2;
    }
    /*
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
    */
};