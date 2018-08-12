#include <vector>
#include <iostream>
#include <string>

using namespace std;

// 大顶堆解
// 注意的地方 每次都把排序好的值放到最后一个位置
// 因为adjust_heap能正常调整堆的前提是array的range是从0开始的
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
/*
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
    int quickSelect(vector<int>& nums, int b, int e, int t){
        if(b==e){return nums[b];}
        int l = b;
        int r = e;
        while(l<r){
            while(l<r && nums[r]>=nums[b]){r--;}
            while(l<r && nums[l]<=nums[b]){l++;}
            swap(nums[l], nums[r]);
        }
        swap(nums[b], nums[r]);
        if(r-b>t){
            return quickSelect(nums, b, r-1, t);
        }
        else if(r-b<t){
            return quickSelect(nums, r+1, e, t-(r-b+1));
        }
        else{
            return nums[r];
        }
    }
};
*/
int main(int argc, char const *argv[])
{
	static const int arr[] = {10, 80, 70, 100, 90, 30, 20};
	// static const int arr[] = {2, 1};
	vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );
	cout << Solution().findKthLargest(vec, 4) << endl;
}