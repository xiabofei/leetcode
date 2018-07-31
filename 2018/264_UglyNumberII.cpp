#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;



// http://www.cnblogs.com/grandyang/p/4743837.html
// ugly number 每次乘{2, 3, 5}三个数
// 这样维护三个list 第一个list每次乘2 第二个list每次乘3 第三个list每次乘5
// 选中哪个list的值作为d当前轮次的ugly number了 则把当前序列的index+1
// 3个list如下
// (1) 1x2, 2x2, 2x2, 3x2, 3x2, 4x2, 5x2...
// (2) 1x3, 1x3, 2x3, 2x3, 2x3, 3x3, 3x3...
// (3) 1x5, 1x5, 1x5, 1x5, 2x5, 2x5, 2x5...
// 如果当前轮次 2 3 5出现相同的最小值 
// 则都要更新上

class Solution {
public:
    int nthUglyNumber(int n) {
    	// 三个下标表示已经产生的第几位的ugly number
    	int i2 = 0;
    	int i3 = 0;
    	int i5 = 0;
    	// 这个serials就相当于是dp了 方便回溯不同位置的ugly number
    	vector<int> serials;
    	serials.push_back(1);
    	while(serials.size()<n){
    		int v2 = serials[i2]*2;
    		int v3 = serials[i3]*3;
    		int v5 = serials[i5]*5;
    		int min_v = min(v2, min(v3, v5));
    		if(min_v==v2){i2++;}
    		if(min_v==v3){i3++;}
    		if(min_v==v5){i5++;}
    		serials.push_back(min_v);
    	}
    	return serials.back();
    }
};