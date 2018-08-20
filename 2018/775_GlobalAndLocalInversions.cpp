#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://blog.csdn.net/liuchuo/article/details/79195105
// 最多允许index相差1的可以大小翻转 
// index相差大于等于2的 只能是左小右大
// 维护一个最大值 从头到尾 必须比相邻两个间隔的元素大

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
    	if(A.size()<=2){return true;}
    	int mx = INT_MIN;
    	for(int i=0; i<A.size()-2; i++){
    		mx = max(mx, A[i]);
    		if(mx>A[i+2]){return false;}
    	}
    	return true;
    }
};