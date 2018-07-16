#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


class Solution {
public:
	void sortColors(vector<int>& nums) {
		if(nums.size()<3){return;}
		int p0 = 0;
		int p2 = nums.size()-1;
		int i = 0;
		while(i<=p2){
			if(nums[i]==0){
				swap(nums[i], nums[p0]);
				i++;
				p0++;
			}
			else if(nums[i]==2){
				swap(nums[i], nums[p2]);
				p2--;
			}
			else{
				i++;
			}
		}
	}
};
