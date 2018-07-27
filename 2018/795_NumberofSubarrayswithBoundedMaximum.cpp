#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 用常规稳定的方法
// http://www.cnblogs.com/grandyang/p/9237967.html
// 遍历所有子数组 + 剪枝
// 学习遍历所有子数组的模板

class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
    	int ret = 0;
    	for(int i=0; i<A.size(); i++){
    		int mx = INT_MIN;
    		for(int j=i; j<A.size(); j++){
    			mx = max(mx, A[j]);
    			if(mx>R) break;
    			if(mx>=L) ret++;
    		}
    	}
    	return ret;
    }
};
