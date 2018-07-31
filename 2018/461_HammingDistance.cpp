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
    int hammingDistance(int x, int y) {
    	int ret = 0;
    	for(int i=0; i<31; i++){
    		ret += (x & 1) ^ (y & 1);
    		x >>= 1;
    		y >>= 1;
    	}
    	return ret;
    }
};