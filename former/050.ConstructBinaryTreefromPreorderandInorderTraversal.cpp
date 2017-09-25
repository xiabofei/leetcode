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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
    	return Solution::build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    static TreeNode* build(vector<int>& preorder, int beginP, int endP,
    				vector<int>& inorder, int beginI, int endI
    	)
    {
    	if ( beginP>endP ) return NULL;
    	TreeNode *root = new TreeNode(preorder[beginP]);
    	int index = beginI;
    	for ( int i=beginI; i<=endI; ++i )
    	{
    		if (inorder[i]==preorder[beginP])
    		{
    			index = i;
    			break;
    		}
    	}
    	int l = index - beginI;
    	int r = endI - index;
    	root->left = Solution::build(preorder, beginP+1, beginP+l, inorder, beginI, beginI+l-1);
    	root->right = Solution::build(preorder, endP-r+1, endP, inorder, endI-r+1, endI);
    	return root;
    }
};