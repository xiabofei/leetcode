#include <iostream>
#include <vector>
#include <map>
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
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
  		stack<TreeNode*> sta1, sta2;
  		if (p) sta1.push(p);
  		if (q) sta2.push(q);
  		while ( !sta1.empty() && !sta2.empty() )
  		{
  			TreeNode *tmp1 = sta1.top(); sta1.pop();
  			TreeNode *tmp2 = sta2.top(); sta2.pop();
  			if ( tmp1->val != tmp2->val ) return false;
  			if ( tmp1->left==NULL && tmp2->left!=NULL ) return false;
  			if ( tmp1->left!=NULL && tmp2->left==NULL ) return false;
  			if ( tmp1->right==NULL && tmp2->right!=NULL ) return false;
  			if ( tmp1->right!=NULL && tmp2->right==NULL ) return false;
  			if ( tmp1->left ) { sta1.push(tmp1->left); sta2.push(tmp2->left); }
  			if ( tmp1->right ) { sta1.push(tmp1->right); sta2.push(tmp2->right); }
  		}
  		return sta1.empty() && sta2.empty();
    }
};