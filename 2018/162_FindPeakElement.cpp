#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://blog.csdn.net/u010367506/article/details/41943309
// 因为most left和most right都是最小 只要出现left比right大就可以了
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	int l = 0;
    	int r = nums.size()-1;
    	while(l<r){
    		int m = (l+r)/2;
    		if(nums[m]<nums[m+1]){
    			l = m+1;
    		}
    		else{
    			r = m;
    		}
    	}
    	return l;
    }
};