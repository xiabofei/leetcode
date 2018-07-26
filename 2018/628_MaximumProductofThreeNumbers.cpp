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
    int maximumProduct(vector<int>& nums) {
    	int ret = 0;
    	vector<int> positive;
    	vector<int> negative;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]>=0){
    			positive.push_back(nums[i]);
    		}
    		else{
    			negative.push_back(-nums[i]);
    		}
    	}
    	const int psize = positive.size();
    	const int nsize = negative.size();
    	if(psize>0){
    		sort(positive.begin(), positive.end());
    	}
    	if(nsize>0){
    		sort(negative.begin(), negative.end());
    	}
    	// 极大值可能出现的四种情况
    	// 0 正 3 负
    	int ret1 = INT_MIN;
    	if(nsize>=3){
    		ret1 = -1 * negative[0] * negative[1] * negative[2];
    	}
    	// 1 正 2 负
    	int ret2 = INT_MIN;
    	if(psize>=1 && nsize>=2){
    		ret2 = positive[psize-1] * negative[nsize-1] * negative[nsize-2];
    	}
    	// 2 正 1 负
    	int ret3 = INT_MIN;
    	if(psize>=2 && nsize>=1){
    		ret3 = -1 * positive[0] * positive[1] * negative[0];
    	}
    	// 3 正 0 负
    	int ret4 = INT_MIN;
    	if(psize>=3){
    		ret4 = positive[psize-1] * positive[psize-2] * positive[psize-3];
    	}
    	return max(max(ret1, ret2), max(ret3, ret4));
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1,2,3};
	Solution().maximumProduct(dat);
	return 0;
}