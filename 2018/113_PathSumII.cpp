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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> ret;
    	vector<int> tmp;
    	Solution::path(root, sum, tmp, ret);
    	return ret;
    }
    void path(
    	TreeNode* root, int sum, vector<int>& tmp, vector<vector<int>>& ret){
    	if(!root){return;}
    	// 压入当前节点
    	tmp.push_back(root->val);
    	// 叶子节点 & 满足pathSum条件
    	if(!root->left && !root->right && root->val==sum){
    		ret.push_back(tmp);
    	}
    	// 走左边
    	Solution::path(root->left, sum-root->val, tmp, ret);
    	// 走右边
    	Solution::path(root->right, sum-root->val, tmp, ret);
    	tmp.pop_back();
    }
};

class Solution1 {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
    	vector<vector<int>> ret;
    	if(!root){return ret;}
    	if(!root->left && !root->right && root->val==sum){
    		vector<int> tmp;
    		tmp.push_back(root->val);
    		ret.push_back(tmp);
    		return ret;
    	}
    	vector<vector<int>> l_ret = Solution::pathSum(root->left, sum-root->val);
    	for(int i=0; i<l_ret.size(); i++){
    		l_ret[i].insert(l_ret[i].begin(), root->val);
    	}
    	vector<vector<int>> r_ret = Solution::pathSum(root->right, sum-root->val);
    	for(int i=0; i<r_ret.size(); i++){
    		r_ret[i].insert(r_ret[i].begin(), root->val);
    	}
    	ret.insert(ret.end(), l_ret.begin(), l_ret.end());
    	ret.insert(ret.end(), r_ret.begin(), r_ret.end());
    	return ret;
    }
};