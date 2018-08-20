#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/7753959.html
// 用nums[i]卡住一头 每次都累加 一定包含nums[i]且在i左侧的能有多少sub array满足条件

// 连续子数组的'乘积'或'和'
// two points思路 一个指针先往前走 找到满足条件的解
// 另一个指针往前推

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    	if(k<=1){return 0;}
    	if(nums.size()==0){return 0;}
    	if(nums.size()==1){return nums[0]<k;}
    	int cnts = 0, last=0, product=1;
    	for(int i=0; i<nums.size(); i++){
    		product *= nums[i]; // 先累乘当前元素
    		while(product>=k && last<nums.size()){
    			product /= nums[last];
    			last++;
    		}
    		cnts += i - last + 1;
    	}
    	return cnts;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {10, 5, 2, 6};
	int k = 100;
	Solution().numSubarrayProductLessThanK(dat, k);
	return 0;
}