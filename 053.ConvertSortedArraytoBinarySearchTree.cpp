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
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
    	return Solution::sort(nums, 0, nums.size()-1);
    }
    static TreeNode* sort(vector<int>& nums, int begin, int end)
    {
    	if ( begin>end ) return NULL;
    	int mid = (begin+end)/2;
    	TreeNode *root = new TreeNode(nums[mid]);
    	root->left = Solution::sort(nums, begin, mid-1);
    	root->right = Solution::sort(nums, mid+1, end);
    	return root;
    }
};