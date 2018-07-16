#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 题意理解
// 	在一个unsorted的数组里面 找到最短的子数组
// 	只要给这个子数组排序好了 整个数组就有序了
// 解法
// 	http://www.cnblogs.com/grandyang/p/6876457.html
//  (1) 从后往前找最长的0→k的升序部分 这样可以保证0→k里面的最大值比之后的最小值要小
//  (2) 从前往后找最长的k→N的降序部分 这样可以保证k→N里面的最小值都比前面最大值要大


class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
    	if(nums.size()<2){return 0;}
    	int shortest = INT_MAX;
    	int val_max = nums[0];
    	int val_min = nums[nums.size()-1];
    	int start = nums.size()-1;
    	int end = 0;
    	for(int i=1; i<nums.size(); i++){
    		// 从后往前找最长升序列
    		val_min = min(val_min, nums[nums.size()-1-i]);
    		if(val_min < nums[nums.size()-1-i]){
    			start = nums.size()-1-i;
    		}
    		// 从前往后找最长升序列
    		val_max = max(val_max, nums[i]);
    		if(val_max > nums[i]){
    			end = i;
    		}
    	}
    	return start>=end ? 0 : end - start + 1;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1, 2, 3, 4};
	Solution().findUnsortedSubarray(dat);
	return 0;
}
