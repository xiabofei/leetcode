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
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n1 = nums1.size();
    	int n2 = nums2.size();
    	int k = n1+n2;
    	if(k&1){
    		return find(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2+1);
    	}
    	else{
    		double ret1 = find(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2);
    		double ret2 = find(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2+1);
    		return (ret1+ret2)/2.0;
    	}
    }
    double find( 
    	vector<int>& nums1, int b1, int e1,
    	vector<int>& nums2, int b2, int e2, int k){
    	if(e2-b2>e1-b1){return find(nums2, b2, e2, nums1, b1, e1, k);}
    	if(b2>e2){return nums1[b1+k-1];}
    	if(k==1){return min(nums1[b1], nums2[b2]);}
        // 核心就是一句话 : 每次选择砍掉 nums1的前k1个元素 或 nums2的前k2个元素
    	int k2 = min(k/2, e2-b2+1);
    	int k1 = k - k2;
    	if(nums1[b1+k1-1]<nums2[b2+k2-1]){
    		return find(nums1, b1+k1, e1, nums2, b2, e2, k2);
    	}
    	else if(nums1[b1+k1-1]>nums2[b2+k2-1]){
    		return find(nums1, b1, e1, nums2, b2+k2, e2, k1);
    	}
    	else{
    		return nums1[b1+k1-1];
    	}
    }
};