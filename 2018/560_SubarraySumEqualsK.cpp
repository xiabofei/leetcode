#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/6810361.html
// 维护一个hashmap 可以用O(n)时间复杂度搞定
// 思路 : 0------n-------N
// 每次累加的是 0 - n 的从头到n的累加
// 在累加到N的时候 判断前面出现了多少个累加是sum-k
// 如果sum-k==0 则只能有一种可能 就是sum==k 这时候初始化sum=0就发挥了作用

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    	int count = 0;
    	if(nums.size()==0){return count;}
    	unordered_map<int, int> sum_cnt{{0,1}};
    	int sum = 0;
    	for(int i=0; i<nums.size(); i++){
    		sum += nums[i];
    		if(sum_cnt.find(sum-k)!=sum_cnt.end()){
    			count += sum_cnt[sum-k];
    		}
    		sum_cnt[sum]++;
    	}
    	return count;
    }
};