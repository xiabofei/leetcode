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
    int findLengthOfLCIS(vector<int>& nums) {
    	if(nums.size()<2){return nums.size();}
    	int longest = 0;
    	int start = 0;
    	int end = 0;
    	for(int i=1; i<nums.size(); i++){
    		if(nums[i-1]<nums[i]){
    			end = i; 
    		}
    		else{
    			longest = max(longest, end - start + 1);
    			start = i;
    			end = i;
    		}
    	}
    	return max(longest, end - start + 1);
    	// cout << longest << endl;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {2, 2, 2, 2, 2};
	Solution().findLengthOfLCIS(dat);
	return 0;
}