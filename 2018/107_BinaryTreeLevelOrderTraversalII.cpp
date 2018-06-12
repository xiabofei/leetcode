#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
    	vector<vector<int>> ret;
    	if(!root){return ret;}
    	queue<TreeNode*> q_curr, q_next;
    	q_curr.push(root);
    	vector<int> tmp;
    	while(!q_curr.empty()){
    		TreeNode* p = q_curr.front();
    		tmp.push_back(p->val);
    		q_curr.pop();
    		if(p->left){q_next.push(p->left);}
    		if(p->right){q_next.push(p->right);}
    		if(q_curr.empty()){
    			ret.push_back(tmp);
    			tmp.clear();
    			swap(q_curr, q_next);
    		}
    	}
    	reverse(ret.begin(), ret.end());
    	return ret;
    }
};