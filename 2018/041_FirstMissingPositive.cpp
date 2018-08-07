#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// https://www.cnblogs.com/AnnieKim/archive/2013/04/21/3034631.html
// 不用额外空间实现 采用"value换到index"这种标准解法

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    	if(nums.size()==0){return 1;}
    	int i=0;
    	while(i<nums.size()){
    		// swap需要满足几个条件
    		// 1) nums[i] 得满足下标的范围
    		// 2) nums[i] 与 nums[nums[i]-1] 不等
    		if(nums[i]!=i+1 && nums[i]>0 && nums[i]<nums.size() && nums[i]!=nums[nums[i]-1]){
    			swap(nums[i], nums[nums[i]-1]);
    		}
    		else{
    			i++;
    		}

    	}
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]!=i+1){
    			return i+1;
    		}
    	}
    	return nums.size()+1;
    }
};