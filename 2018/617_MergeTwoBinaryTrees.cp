#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

// http://www.cnblogs.com/grandyang/p/7058935.html
// 当t1或t2为NULL的时候 有个优化点 直接返回t1或t2

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};   

class Solution {
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if(!t1){return t2;}
		if(!t2){return t1;}
		TreeNode* node = new TreeNode(t1->val+t2->val);
		node->left = mergeTrees(t1->left, t2->left);
		node->right = mergeTrees(t1->right, t2->right);
		return node;
	}
};