#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int ret = 0;
		if(nums.size()==0){return ret;}
		sort(nums.begin(), nums.end());
		for(int i=0; i<nums.size(); i+=2){
			ret += nums[i];
		}
		return ret;
	}
};