#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
    	const int m = nums1.size();
    	const int n = nums2.size();
    	int k = m+n;
    	if ( k&1 )
    	{
            return Solution::findMedian(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2+1);
    	}   
    	else
    	{
            return 1.0*(Solution::findMedian(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2)+
                    Solution::findMedian(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2+1))/2.0;
    	} 
    }
    static double findMedian(
            vector<int>& nums1, int begin1, int end1,
            vector<int>& nums2, int begin2, int end2,
            int k)
    {
        if ( end1-begin1 > end2-begin2 ) return Solution::findMedian(nums2, begin2, end2, nums1, begin1, end1, k);
        if ( end1<begin1 ) return nums2[begin2+k-1];
        if ( k==1 ) return min(nums1[begin1], nums2[begin2]);
        int k1 = min(k/2, end1-begin1+1);
        int k2 = k-k1;
        if ( nums1[begin1+k1-1]<nums2[begin2+k2-1] )
        {
            return Solution::findMedian(nums1, begin1+k1, end1, nums2, begin2, end2, k2);
        }
        else if ( nums1[begin1+k1-1]>nums2[begin2+k2-1] )
        {
            return Solution::findMedian(nums1, begin1, end1, nums2, begin2+k2, end2, k1);
        }
        else
        {
            return nums1[begin1+k1-1];
        }
    }
};