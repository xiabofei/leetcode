#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 这个数组有特殊性 长度是n 所有元素是 0 ~ n-1
// 因此可以用特殊的解法

// 遍历到i 则0-i必须都出现在i里面 就可以分割
// 由于没有重复 因此只要在i的位置的最大值是i就可以切开了!
// http://www.cnblogs.com/grandyang/p/8823944.html

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
    	if(arr.size()==0){return 0;}
    	if(arr.size()==1){return 1;}
    	int mx = -1;
    	int cnt = 0;
    	for(int i=0; i<arr.size(); i++){
    		mx = max(mx, arr[i]);
    		if(mx == i){
    			cnt++;
    		}
    	}
    	return cnt;
    }
};