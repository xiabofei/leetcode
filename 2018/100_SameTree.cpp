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
    bool isSameTree(TreeNode* p, TreeNode* q) {
    	if(!p && !q){return true;}
    	if(!p && q){return false;}
    	if(!q && p){return false;}
    	if(p->val!=q->val){return false;}
    	bool l = Solution::isSameTree(p->left, q->left);
    	if(!l){return false;}
    	bool r = Solution::isSameTree(p->right, q->right);
    	return l && r;
    }
};