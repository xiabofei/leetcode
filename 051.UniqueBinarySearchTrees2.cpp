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
    vector<TreeNode*> generateTrees(int n)
    {
    	return Solution::generate(1, n); 
    }
    static vector<TreeNode*> generate(int min, int max)
    {
    	vector<TreeNode*> ret;
    	if ( min>max ){
    		ret.push_back(NULL);
    		return ret;
    	}
    	for ( int i=min; i<=max; ++i ){
    		vector<TreeNode*> l = Solution::generate(min, i-1);
    		vector<TreeNode*> r = Solution::generate(i+1, max);
    		for ( int j=0; j<l.size(); ++j ){
    			for ( int k=0; k<r.size(); ++k ){
    				TreeNode *root = new TreeNode(i);
    				root->left = l[j];
    				root->right = r[k];
    				ret.push_back(root);
    			}
    		}
    	}
    	return ret;
    }
};