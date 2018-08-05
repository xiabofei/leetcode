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

// https://blog.csdn.net/qq508618087/article/details/51395409
// 2维dp需要O(n³)时间复杂度 联想到 有几个1维dp需要O(n²)复杂度的
// 联想到3sum 4sum这两道题
// dp[i][j]表示nums[i]到nums[j]最大可以构成的Coins
// l --------- end
//   --m--
//        r--- end
// 每次定左边的l 根据左边的l定右边的r 再扫描l→r之间

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	int ret = 0;
    	if(nums.size()==0){return 0;}
    	// 头和尾 都补上1
    	nums.insert(nums.begin(), 1);
    	nums.insert(nums.end(), 1);
    	const int len = nums.size();
    	vector<vector<int>> dp(len, vector<int>(len, 0));
    	for(int l=len-3; l>=0; l--){
    		// 限制住左侧的起点
    		for(int r=l+2; r<len; r++){
    			// 限制住右侧终点
    			for(int m=l+1; m<r; m++){
    				// 扫中间的点
    				dp[l][r] = max(dp[l][r], nums[l]*nums[m]*nums[r]+dp[l][m]+dp[m][r]);
    			}
    		}
    	}
    	return dp[0][len-1];
    }
};