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
    int sumNumbers(TreeNode* root) {
    	int one_path = 0;
    	int all_paths = 0;
    	Solution::calculate(root, one_path, all_paths);
    	return all_paths;
    }
    void calculate(TreeNode* root, int one_path, int& all_paths){
    	if(!root){return;}
    	if(!root->left && !root->right){
    		all_paths = all_paths + one_path*10 + root->val;
    	}
    	if(root->left){
    		Solution::calculate(root->left, one_path*10+root->val, all_paths);
    	}
    	if(root->right){
    		Solution::calculate(root->right, one_path*10+root->val, all_paths);
    	}
    }
};