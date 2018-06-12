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
    void flatten(TreeNode* root){
    	if(!root){return;}
    	TreeNode* p = new TreeNode(0);
    	stack<TreeNode*> sta;
    	sta.push(root);
    	while(!sta.empty()){
    		TreeNode* curr = sta.top();
    		sta.pop();
    		p->right = curr;
    		p->left = NULL;
    		p = p->right;
    		if(curr->right){sta.push(curr->right);}
    		if(curr->left){sta.push(curr->left);}
    	}
    }
};

// class Solution {
// public:
//     void flatten(TreeNode* root) {
//     	if(!root){return;}
//     	if(root->left){Solution::flatten(root->left);}
//     	if(root->right){Solution::flatten(root->right);}
//     	TreeNode* tmp = root->right;
//     	root->right = root->left;
//     	root->left = NULL;
//     	while(root->right){root = root->right;}
//     	root->right = tmp;
//     }
// };