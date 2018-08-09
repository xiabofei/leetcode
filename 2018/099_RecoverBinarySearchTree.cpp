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

// https://blog.csdn.net/qq508618087/article/details/50516683 
// 思路 : 中序遍历BST可以获得完全有序的序列
// 比如中序遍历获得了数组 1 5 3 4 2 6
// 显然'5'和'2'是逆序的
// 第一次出现pre>curr 则first为pre second为curr
// 第二次出现pre>curr 则second再更新为curr
// 如果mismatch的点是相邻的 则first和second是相邻的 因此在第一次出现的时候就要给second记录为curr
// 要把整个BST遍历完 才能获得正确结果

class Solution {
public:
    TreeNode* pre = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;
    void recoverTree(TreeNode* root) {
    	recover(root);
    	swap(first->val, second->val);
    }
    void recover(TreeNode* root){
    	if(!root){return;}
    	recover(root->left);
    	if(pre && pre->val > root->val){
    		if(!first){
    			first = pre;
    		}
    		second = root;
    	}
    	pre = root;
    	recover(root->right);
    }
};