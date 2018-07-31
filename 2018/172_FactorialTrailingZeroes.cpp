#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://blog.csdn.net/sinat_35261315/article/details/79363470
// 统计小于n的数字中包含多少个5
// 5 25 75 ...
// 比如看25的时候 5*5已经在看5的时候拆出来了

class Solution {
public:
    int trailingZeroes(int n) {
    	int ret = 0;
    	for(int m=5; n/m>0; m *= 5){
    		ret += n/m;
    	}
    	return ret;
    }
};