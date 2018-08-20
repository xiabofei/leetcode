#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 两个差值的 
// sort一把 大小有序
// 通过hashmap 走O(N)可以搞定

class Solution {
public:
	int findPairs(vector<int>& nums, int k) {
		if(nums.size()==0){return 0;}
		int cnt = 0;
		sort(nums.begin(), nums.end());
		unordered_set<int> exist;
		if(k==0){
			// 如果k==0 判断有多少个重复的
			cnt = 0;
			int val_cnt = 1;
			for(int i=1; i<nums.size(); i++){
				if(nums[i]==nums[i-1]){
					val_cnt++;
				}
				else{
					cnt += val_cnt>=2 ? 1 : 0;
					val_cnt=1;
				}
			}
			cnt += val_cnt>=2 ? 1 : 0;
		}
		else{
			for(int i=0; i<nums.size(); i++){
				if(exist.find(nums[i])==exist.end() && exist.find(nums[i]-k)!=exist.end()){
					cnt++;
				}
				exist.insert(nums[i]);
			}

		}
		return cnt;
	}
};

int main(int argc, char const *argv[])
{
	vector<int> nums = {3, 1, 4, 1, 5};
	int k = 2;
	Solution().findPairs(nums, k);
	return 0;
}