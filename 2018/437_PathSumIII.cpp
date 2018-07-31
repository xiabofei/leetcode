#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// https://leetcode.com/problems/path-sum-iii/discuss/91877/C++-5-Line-Body-Code-DFS-Solution
// 题意限定了 只能是由上到下的路径
// 有种代码简洁但是时间复杂度略高的计算
// 从每个节点开始 都往下走
// 采用双递归

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
    	if(!root){return 0;}
    	return help(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int help(TreeNode* root, int pre, const int sum){
    	if(!root){return 0;}
    	int curr = pre + root->val;
    	return (curr==sum) + help(root->left, curr, sum) + help(root->right, curr, sum);
    }
};