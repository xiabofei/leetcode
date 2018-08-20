#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 核心就是维护一个hashset 记录已经访问过的path

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
    	if(nums.size()<2){return nums.size();}
    	int longest = 0;
    	unordered_set<int> index;
    	for(int i=0; i<nums.size(); i++){
    		int curr = 0;
    		int idx = nums[i];
    		while(index.find(idx)==index.end()){
    			curr++;
    			index.insert(idx);
    			idx = nums[idx];
    		}
    		longest = max(longest, curr);
    	}
    	return longest;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {5,4,0,3,1,6,2};
	Solution().arrayNesting(dat);
	return 0;
}