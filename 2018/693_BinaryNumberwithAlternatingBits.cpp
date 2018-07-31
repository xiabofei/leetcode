#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
    	int ret = true;
    	int tmp = n & 1;
    	n = n >> 1;
    	for(int i=0; i<30; i++){
    		// 一旦进入循环 且n为0 则一定满足条件
    		if(n==0){
    			return true;
    		}
    		if(!(n&1)^(tmp&1)){
    			return false;
    		}
    		tmp = n & 1;
    		n = n >> 1;
    	}
    	return ret;
    }
};