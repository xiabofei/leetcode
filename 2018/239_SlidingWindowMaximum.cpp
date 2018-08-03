#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;


// http://www.cnblogs.com/grandyang/p/4656517.html
// 用双向队列的做法
// 队列中始终保持不超过1个元素
// 维护一个deque 保持当前k个长度的窗口 最大值一定在front就可以了

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int> ret;
    	if(k==0 || nums.size()==0){return ret;}
    	deque<int> dq;
    	// 开始k个元素不往ret中灌数据 最大值前面的都干掉 最大值后面的留下来
    	// 1 2 3 2 1 → 最终留下来的是 3 2
    	// 相当于最大值留在front就可以了
    	dq.push_back(0);
    	for(int i=1; i<k; i++){
    		while(!dq.empty() && nums[dq.back()]<nums[i]){dq.pop_back();}
    		dq.push_back(i);
    	}
    	ret.push_back(nums[dq.front()]);
    	// 迭代剩余的元素
    	for(int i=k; i<nums.size(); i++){
    		// 如果正好下标是上一个windows的起始点 则队头先出一个元素
    		if(dq.front()==i-k){
    			dq.pop_front();
    		}
    		// 判断进入队尾的条件
    		while(!dq.empty() && nums[dq.back()]<nums[i]){dq.pop_back();}
    		dq.push_back(i);
    		ret.push_back(nums[dq.front()]);
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1,3,1,2,0,5};
	Solution().maxSlidingWindow(dat, 3);
	return 0;
}
