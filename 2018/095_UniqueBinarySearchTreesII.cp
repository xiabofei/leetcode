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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> ret;
        if(n<1){return ret;}
    	return Solution::generate(1, n);
    }
    vector<TreeNode*> generate(int b, int e){
    	vector<TreeNode*> ret;
    	if(b>e){
    		ret.push_back(NULL);
    		return ret;
        }
    	if(b==e){
    		ret.push_back(new TreeNode(b));
    		return ret;
    	}
    	vector<TreeNode*> l_opts;
    	vector<TreeNode*> r_opts;
    	// 遍历b到e 轮流让当前node成为root 并切分左右 
    	for(int i=b; i<=e; i++){
    		l_opts = Solution::generate(b, i-1);
    		r_opts = Solution::generate(i+1, e);
    		for(int l=0; l<l_opts.size(); l++){
    			for(int r=0; r<r_opts.size(); r++){
    				TreeNode* curr = new TreeNode(i);
    				curr->left = l_opts[l];
    				curr->right = r_opts[r];
                    ret.push_back(curr);
    			}
    		}
    	}
        return ret;
    }
};