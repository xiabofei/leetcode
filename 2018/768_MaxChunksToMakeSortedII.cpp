#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/8823944.html
// 用一种想到的直观思路
// 0:i的最大值 >= i+1:N的最小值
// 就可以满足切分的条件 

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	if(arr.size()==0){return 0;}
    	if(arr.size()==1){return 1;}
    	// 求0:i的最大值
    	vector<int> left_mx(arr.size(), INT_MIN);
    	left_mx[0] = arr[0];
    	for(int i=1; i<arr.size(); i++){
    		left_mx[i] = max(left_mx[i-1], arr[i]);
    	}
    	// 求i:N的最小值
    	int mi = INT_MAX;
    	vector<int> right_mi(arr.size(), INT_MAX);
    	right_mi[arr.size()-1] = arr.back();
    	for(int i=arr.size()-2; i>=0; i--){
    		right_mi[i] = min(right_mi[i+1], arr[i]);
    	}
    	// 扫描找所有可能的切分点
    	int ret = 1;
    	for(int i=0; i<arr.size()-1; i++){
    		// 这一步是精髓 算的时候都照着i:N算最小值
    		// 比较的时候把下标变成i+1
    		if(left_mx[i]<=right_mi[i+1]){
    			ret++;
    		}
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1, 0, 1, 3, 2};
	Solution().maxChunksToSorted(dat);
	return 0;
}