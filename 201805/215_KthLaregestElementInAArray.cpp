#include <vector>
#include <iostream>
#include <string>

using namespace std;

/*
// 大顶堆解法
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	for(int i = nums.size()/2-1; i>=0; i--){
    		Solution::adjust_heap(nums, i, nums.size());
    	}
    	for(int i = 0; i<k; i++){
    		swap(nums[0], nums[nums.size()-1-i]);
    		Solution::adjust_heap(nums, 0, nums.size()-1-i);
    	}
    	return nums[nums.size()-k];
    }
    void adjust_heap(std::vector<int>& nums, int b, int e){
    	int curr = b;
    	while(curr<=e/2-1){
    		int child = 2*curr+1;
    		if(child+1<e && nums[child]<nums[child+1]){
    			child += 1;
    		}
    		if(nums[curr]>=nums[child]){
    			break;
    		}
    		swap(nums[curr], nums[child]);
    		curr = child;
    	}
    }
};
*/
// 快排序解法 
// 核心: 每次执行完一个pass之后 判断要找的 topk 可能出现在pivot的 左侧 / 右侧 / 当前位置
// target意义是: 每次执行完quick之后,要找到多少比pivot小的值
// 1) 如果target比pivot左侧元素小 则目标元素在pivot左侧 target个数不变
// 2) 如果target比pivot左侧的元素大 则目标元素在pivot右侧 且target应减少rp-b+1
// 3) 如果target正好与pivot左侧的元素数目相等 则pivot就是要找的元素
// 采用递归的方法 终止条件和一些corner case需要设定好
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    	return Solution::quickSelect(nums, 0, nums.size()-1, nums.size()-k);
    }
    int quickSelect(vector<int>& nums, int b, int e, int target){
    	if(b==e && target==0){return nums[b];}
    	if(b+1==e && target==1){return max(nums[b], nums[e]);}
    	int pivot = nums[b];
    	int lp = b;
    	int rp = e;
    	while(lp<rp){
    		while(lp<rp && nums[rp]>=pivot){rp--;}
    		while(lp<rp && nums[lp]<=pivot){lp++;}
    		swap(nums[lp], nums[rp]);
    	}
    	swap(nums[b], nums[rp]);
    	if(rp-b>target){
    		return Solution::quickSelect(nums, b, rp-1, target);
    	}
    	if(rp-b<target){
    		return Solution::quickSelect(nums, rp+1, e, target-(rp-b+1));
    	}
    	return nums[rp];
    }
};
int main(int argc, char const *argv[])
{
	static const int arr[] = {10, 80, 70, 100, 90, 30, 20};
	// static const int arr[] = {2, 1};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	cout << Solution().findKthLargest(vec, 4) << endl;
}