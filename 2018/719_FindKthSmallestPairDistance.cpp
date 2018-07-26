#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/8627783.html
// 这个binary search比较特殊 二分查找的是distance
// 每次都把当前distance下的cnt算出来
// distance是多少时 比distance小的正好等于k

class Solution {
public:
	int smallestDistancePair(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int small = 0; // 间距的下限
		int big = nums.back() - nums[0]; // 间距的下限
		while(small < big){
			int dist = (small + big) / 2;
			int cnt = 0; // 有多少个pair满足比dist小的
			int start = 0;
			for(int i = 0; i < nums.size(); i++){
				// 扫一遍nums[start]到nums[i]这个区间
				// 统计有多少比dist小的 
				while(start<nums.size() && nums[i] - nums[start] > dist){
					start++;
				}
				cnt += i - start;
			}
			if(cnt<k){
				// 满足比dist小的pair比k少 则增加dist使满足条件的Pair更多
				small = dist + 1;
			}
			else{
				big = dist;
			}
		}
		return big;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {62,100,4};
	int k = 2;
	Solution().smallestDistancePair(dat, k);
	return 0;
}