#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 题意
//	从数组中找到所有可以满足构成三角形的triple
// 	深搜 + 剪枝(排序)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	int valid = 0;
    	dfs(valid, nums, 0, 0, 0);
    	return valid;
    }
    void dfs(int& valid, vector<int>& nums, int sum, int cnt, const int begin){
    	for(int i=begin; i<nums.size(); i++){
    		if(cnt<2){
    			sum += nums[i];
    			cnt++;
    			dfs(valid, nums, sum, cnt, i+1);
    			sum -= nums[i];
    			cnt--;
    		}
    		else{
    			if(nums[i]>=sum){
    				return;
    			}
    			valid++;
    		}
    	}
    }
};