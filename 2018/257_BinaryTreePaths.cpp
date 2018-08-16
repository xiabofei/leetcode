#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
    	vector<string> ret;
    	string tmp = "";
    	dfs(ret, root, tmp);
    	return ret;
    }
    void dfs(vector<string>& ret, TreeNode* root, string tmp){
    	if(!root){return;}
    	if(!root->left && !root->right){
    		ret.push_back(tmp + to_string(root->val));
    		return;
    	}
    	tmp += to_string(root->val) + "->";
    	dfs(ret, root->left, tmp);
    	dfs(ret, root->right, tmp);
    }
};
