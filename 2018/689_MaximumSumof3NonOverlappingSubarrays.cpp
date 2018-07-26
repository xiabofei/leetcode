#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 下标太绕 先过

class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
    	if(nums.size()<3){
    		vector<int> dump;
    		return dump;
    	}
    	// 先对数组做累加(子数组和问题的常用技巧)
    	vector<int> accmu(nums.size(), 0);
    	accmu[0] = nums[0];
    	for(int i=1; i<nums.size(); i++){
    		accmu[i] = accmu[i-1] + nums[i];
    		// cout << accmu[i] << endl;
    	}
    	// 求某个点left 最大k_length子数组起点长度
    	vector<int> left_sum(nums.size(), 0);
    	for(int i=k; i<nums.size(); i++){
    		int curr = accmu[i-1] - (i==k ? 0 : accmu[i-1-k]);
    		int last = accmu[left_sum[i-1]-1+k] - (left_sum[i-1]==0 ? 0 : accmu[left_sum[i-1]-1]);
    		// cout << "i:" << i << " curr:" << curr << " last:" << last << endl;
    		left_sum[i] = curr > last ? i-k : left_sum[i-1];
    	}
    	// 求某个点right 最大k_length子数组起点长度
    	vector<int> right_sum(nums.size(), nums.size()-k);
    	for(int i=nums.size()-1-k; i>=0; i--){
    		int curr = accmu[i+k] - accmu[i];
    		int last = accmu[right_sum[i+1]-1+k] - accmu[right_sum[i+1]-1];
    		// cout << "i:" << i << " curr:" << curr << " last:" << last << endl;
    		right_sum[i] = curr > last ? i+1 : right_sum[i+1];
    	}
    	/*
    	for(int i=0; i<left_sum.size(); i++){
    		cout << left_sum[i] << " ";
    	}
    	cout << endl;
    	for(int i=0; i<right_sum.size(); i++){
    		cout << right_sum[i] << " ";
    	}
    	cout << endl;
    	*/
    	// 走一遍获得最大值
    	vector<int> ret(3, -1);
    	int largest = INT_MIN;
    	for(int i=k; i<=nums.size()-2*k; i++){
    		int l = accmu[left_sum[i]-1+k] - (left_sum[i]==0 ? 0 : accmu[left_sum[i]-1]);
    		int r = accmu[right_sum[i+k-1]-1+k] - accmu[right_sum[i+k-1]-1];
    		int m = accmu[i+k-1] - accmu[i-1];
    		// cout << "l:" << left_sum[i] << " m:" << i << " r:" << right_sum[i+k-1] << endl;
    		// cout << " :" << l << "  :" << m << "  :" << r << endl;
    		if(largest<l+r+m){
    			largest = l + r + m;
    			ret[0] = left_sum[i];
    			ret[1] = i;
    			ret[2] = right_sum[i+k-1];
    		}
    	}
    	// cout << ret[0] << endl;
    	// cout << ret[1] << endl;
    	// cout << ret[2] << endl
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	vector<int> dat = {7,13,20,19,19,2,10,1,1,19};
	int k = 3;
	Solution().maxSumOfThreeSubarrays(dat, k);
	return 0;
}