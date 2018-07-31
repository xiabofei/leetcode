#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 用模拟的方法太复杂 用数学方法
// https://blog.csdn.net/u012814856/article/details/72710519
// x为移动后的平均长度, min为远数组最小值, m为移动的次数, sum为原数组的和
// x = min + m
// sum + m(n-1) = x*n
// sum + mn - m = min*n + mn
// m = sum - min*n
// 因此只需要求出来sum和min就可以了

class Solution {
public:
    int minMoves(vector<int>& nums) {
    	int sum = 0;
    	int mi = INT_MAX;
    	for(int i=0; i<nums.size(); i++){
    		sum += nums[i];
    		mi = min(mi, nums[i]);
    	}
    	return sum - mi*nums.size();
    }
};