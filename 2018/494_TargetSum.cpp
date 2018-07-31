#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>


using namespace std;

class Solution {
public:
	int findTargetSumWays(vector<int>& nums, int S) {
		// sort(nums.begin(), nums.end());
    	// 加入剪枝操作 记录nums[i]往后最大的值和最小的值 如果S-sum>最大值 S-sum<最小值 则剪枝
		vector<int> accmu(nums.size(), 0);
		accmu[0] = nums[0];
		for(int i=1; i<nums.size(); i++){
			accmu[i] = accmu[i-1] + nums[i];
		}
		int count = 0;
		dfs(nums, accmu, count, 0, S, 0);
		return count;
	}
	void dfs(
		vector<int>& nums, vector<int>& accmu, int& count, int sum, int S, const int begin){
		if(begin==nums.size()){
			count += (sum==S);
			return;
		}
		int range = accmu[nums.size()-1] - accmu[begin];
		if(abs(S - (sum+nums[begin]))<=range){
			dfs(nums, accmu, count, sum+nums[begin], S, begin+1);
		}
		if(abs(S - (sum-nums[begin]))<=range){
			dfs(nums, accmu, count, sum-nums[begin], S, begin+1);
		}
	}
};