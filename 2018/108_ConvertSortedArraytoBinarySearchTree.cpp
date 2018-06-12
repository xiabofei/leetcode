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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	return Solution::convert(nums, 0, nums.size()-1);
        
    }
    TreeNode* convert(vector<int>& nums, int b, int e){
    	if(b>e){return NULL;}
    	if(b==e){return new TreeNode(nums[b]);}
    	int m = (b+e)/2;
    	TreeNode* curr = new TreeNode(nums[m]);
    	curr->left = Solution::convert(nums, b, m-1);
    	curr->right = Solution::convert(nums, m+1, e);
    	return curr;
    }
};