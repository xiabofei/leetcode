#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <priority_queue>

using namespace std;

// http://www.cnblogs.com/grandyang/p/4896673.html
// 维护两个堆 最终达到的效果是每个堆存半截data stream 
// 算法原理:
// 		小堆的堆顶存放更小的半截中 最大的那个
// 		大堆的堆顶存放更大的半截中 最小的那个
// 		如果 小堆与大堆size相等 则median就是小堆top与大堆top的均值
// 		如果 小堆size比大堆大 则median就是小堆top的值
// 算法流程:
// 		有新数加入 调整堆 先灌入small中 再把small的top分给large small加入一个 经过调整堆之后 又让给large一个
// 		强行保证small的size要大于large 则判断一把 如果large元素多 则把large的top元素让出来
// 		这里无论是large还是small 让出来一个元素跟上pop
// 时间复杂度 加入元素调整的复杂度是2*log(N) 寻找median的时间复杂度是O(1)

class MedianFinder {
	priority_queue<long> small, large;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
    	small.push(num);
    	large.push(-small.top());
    	small.pop();
    	if(small.size()<large.size()){
    		small.push(-large.top());
    		large.pop();
    	}
    }
    
    double findMedian() {
    	if(small.size()==large.size()){
    		return 0.5*small.top() - 0.5*large.top();
    	}
    	else{
    		return small.top();
    	}
    }
};