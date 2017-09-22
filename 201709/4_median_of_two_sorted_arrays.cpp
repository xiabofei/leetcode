#include <iostream>
#include <vector>

using namespace std;

/*
Tips:
1) 二分查找技巧: 
	每次砍下去k/2 下次再递归的时候再砍下去k/2
2) 奇数中位数和偶数中位数分开讨论
3) 需要讨论两个数组长短的 就直接强行调换顺序 避免讨论
4) 递归的返回条件就分类讨论
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	const int k = nums1.size() + nums2.size();
    	if (k&1){
    		return 1.0 * Solution::find_median(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2 + 1);
    	}
    	else{
    		int part1 = Solution::find_median(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2);
    		int part2 = Solution::find_median(nums1, 0, nums1.size()-1, nums2, 0, nums2.size()-1, k/2 + 1);
    		return (part1 + part2) / 2.0;
    	}
    }

    static double find_median(
    	vector<int>& nums1, int start1, int end1, 
    	vector<int>& nums2, int start2, int end2, int k){
    	// ensure size of nums1 is not larger than size of nums2
    	if(end1 - start1 > end2 - start2){
    		return Solution::find_median(nums2, start2, end2, nums1, start1, end1, k);
    	}
    	// occur when all numbers in nums1 are smaller than any number of nums2
    	// and nums1 is much shorter than nums2
    	if(start1 > end1){ 
    		return nums2[k-1];
    	}
    	if(k==1){
    		return min(nums1[start1], nums2[start2]);
    	}
    	const int k1 = min(k/2, end1 - start1 + 1);
    	const int k2 = k - k1;
    	if(nums1[start1 + k1 -1] < nums2[start2 + k2 -1]){
    		return Solution::find_median(nums1, start1+k1, end1, nums2, start2, end2, k2);
    	}
    	else if(nums1[start1 + k1 -1] > nums2[start2 + k2 -1]){
    		return Solution::find_median(nums1, start1, end1, nums2, start2+k2, end2, k1);
    	}
    	else{
    		return nums1[start1 + k1 -1];
    	}
    }
};

int main(int argc, char const *argv[])
{
	/* code */
	vector<int> nums1;
	nums1.push_back(1);
	nums1.push_back(3);
	vector<int> nums2;
	nums2.push_back(2);
	cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
}
