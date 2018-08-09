#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这里用了一个返回值的技巧
// 如果left或者right是平衡的 则返回最大深度
// 如果left或者right有不平衡 则返回-1

class Solution {
public:
    bool isBalanced(TreeNode* root){
    	return Solution::balanced(root)!=-1;
    }
    int balanced(TreeNode* root){
    	if(!root){return 0;}
    	if(!root->left && !root->right){return 1;}
    	int l = Solution::balanced(root->left);
    	if(l==-1){return -1;}
    	int r = Solution::balanced(root->right);
    	if(r==-1){return -1;}
    	if(abs(l-r)>1){return -1;}
    	return max(l, r)+1;
    }
};