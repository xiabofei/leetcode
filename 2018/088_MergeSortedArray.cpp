#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	// 从后往前merge 非常clever的思路
    	int idx = m+n-1;
    	int i1 = m-1;
    	int i2 = n-1;
    	while(i1>=0 && i2>=0){
    		if(nums1[i1]>nums2[i2]){
    			nums1[idx--] = nums1[i1--];
    		}
    		else{
    			nums1[idx--] = nums2[i2--];
    		}
    	}
    	while(i2>=0){
    		nums1[idx--] = nums2[i2--];
    	}
    }
};