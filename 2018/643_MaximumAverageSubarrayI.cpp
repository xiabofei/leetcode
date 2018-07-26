#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 累加
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    	vector<double> sum(nums.size()+1, 0); 
    	for(int i=1; i<=nums.size(); i++){
    		sum[i] = sum[i-1] + nums[i-1];
    	}
    	// sum(N-k, N) = sum(0, N) - sum(0, N-k)
    	int max_k = INT_MIN;
    	for(int i=k; i<=nums.size(); i++){
    		int local = sum[i] - sum[i-k];
    		max_k = max(max_k, local);
    	}
    	return max_k / double(k);
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {-1};
	Solution().findMaxAverage(dat, 1);
	return 0;
}