#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 切分成k个equal的 就可以用dfs了
// 每个数字都可以计入tmp的和 也可以不计入
// 核心 : 满足条件了 从头开始找; 没满足条件的 持续往后找
// 可以用一个used存放用过的index

class Solution {
public:
	bool canPartitionKSubsets(vector<int>& nums, int k) {
		int total = 0;
		for(int i=0; i<nums.size(); i++){
			total+=nums[i];
		}
		if(total%k){
			return false;
		}
		int target = total/k;
		vector<bool> used(nums.size(), false);
		return dfs(nums, used, target, 0, 0, k);
	}
	bool dfs(
		vector<int>& nums, vector<bool>& used, 
		const int target, const int b, int tmp, int k){
    	// 只要剩一个 就肯定满足条件
		if(k==1){return true;}
    	// tmp满足target 则可以从头开始再找
		if(tmp==target){return dfs(nums, used, target, 0, 0, k-1);}
    	// 尝试让当前的tmp满足target的各种可能
		for(int i=b; i<nums.size(); i++){
    		// 在之前形成子数组和为target的过程中用上了
			if(used[i]){continue;}
			used[i] = true; 
    		// 自己这个target用一把
			if(dfs(nums, used, target, i+1, tmp+nums[i], k)){
				return true;
			}
    		// 让给其他的target用
			used[i] = false;
		}
		return false;
	}
};
