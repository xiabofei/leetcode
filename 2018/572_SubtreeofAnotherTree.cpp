#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
    	if(!s && !t){return true;}
    	if(!s && t){return false;}
    	if(s && !t){return false;}
    	bool val = false;
    	if(s->val==t->val){
    		val = Solution::isSame(s, t);
    	}
    	if(val){return true;}
    	bool l = Solution::isSubtree(s->left, t);
    	if(l){return true;}
    	bool r = Solution::isSubtree(s->right, t);
    	return r;
    }
    bool isSame(TreeNode* s, TreeNode* t){
    	if(!s && !t){return true;}
    	if(!s && t){return false;}
    	if(s && !t){return false;}
    	bool val = s->val == t->val;
    	bool l = Solution::isSame(s->left, t->left);
    	bool r = Solution::isSame(s->right, t->right);
    	return val && l && r;
    }
};