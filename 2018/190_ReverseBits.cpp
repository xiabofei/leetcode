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
    uint32_t reverseBits(uint32_t n) {
    	int ret = 0;
    	for(int i=0; i<32; i++){
    		if(n&1){
    			ret += pow(2, (32-1-i));
    		}
    		n = n>>1;
    	}
    	return ret;
    }
};