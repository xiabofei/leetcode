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
	int singleNumber(vector<int>& nums) {
		unordered_map<int, int> num_cnts;
		for(int i=0; i<nums.size(); i++){
			num_cnts[nums[i]]++;
			if(num_cnts[nums[i]]==3){
				num_cnts.erase(nums[i]);
			}
		}
		return num_cnts.begin()->first;
	}
};