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
// pathSum用先序遍历 每次以root / root->left / root->right为开头
// preorder遍历了所有途径当前节点path

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(!root){return 0;}
        int from_curr = preorder(root, 0, sum);
        int from_left = pathSum(root->left, sum);
        int from_right = pathSum(root->right, sum);
        return  from_curr + from_left + from_right;
    }
    int preorder(TreeNode* root, int pre, const int sum){
        if(!root){return 0;}
        int curr = pre+root->val==sum;
        int left = preorder(root->left, pre+root->val, sum);
        int right = preorder(root->right, pre+root->val, sum);
        return curr + left + right;
    }
};
