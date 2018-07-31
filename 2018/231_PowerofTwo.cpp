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
    bool isPowerOfTwo(int n) {
    	if(n<=0){return false;}
    	int ret = 0;
    	for(int i=0; i<31; i++){
    		ret += n&1;
    		n = n >> 1;
    	}
    	// while(n>0){
    	// 	ret += n&1;
    	// 	n = n >> 1;

    	// }
    	return ret==1;
    }
};