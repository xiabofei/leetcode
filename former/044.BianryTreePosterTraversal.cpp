#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root)
    {
    	vector<int> ret;
    	stack<TreeNode*> sta;
    	TreeNode *curr = root;
    	map<TreeNode *, bool> visited;
    	while ( !sta.empty() || curr ) 
    	{
    		if ( curr )
    		{
    			sta.push(curr);
    			curr = curr->left;
    		}
    		else
    		{
    			curr = sta.top(); // 后续遍历不能马上把sta.top()从栈中弹出来
    			// 两种情况可以让这个元素放入ret
    			// 1. 右子树为空
    			// 2. 这个点已经被访问过了
    			// 过后为了再从stack中弹出元素 需要将curr置为NULL
    			if ( !curr->right || visited.find(curr)!=visited.end() )
    			{
    				ret.push_back(curr->val);
    				sta.pop();
    				curr = NULL;
    			}
    			else
    			{
    				curr = curr->right;
    				visited[sta.top()] = true;
    			}
    		}
    	}
    	return ret;
    }
};