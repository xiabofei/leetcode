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

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    	if(!root){return NULL;}
    	if(root==p || root==q){return root;}
    	TreeNode* l = Solution::lowestCommonAncestor(root->left, p, q);
    	TreeNode* r = Solution::lowestCommo nAncestor(root->right, p, q);
    	if(!l && !r){return NULL;}
    	if((l==q && r==p) || (l==p && r==q)){return root;}
    	return l ? l : r;
    }
};
