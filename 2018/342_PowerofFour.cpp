#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 1的个数只有1个
// 遇到1之前 只有偶数个0
// 处理左移后变成0的停止条件


class Solution {
public:
    bool isPowerOfFour(int num) {
    	if(num<=0){return false;}
    	int ones = 0;
    	int zeros = 0;
    	for(int i=0; i<31; i++){
    		if(num==0){break;}
    		if(num & 1){
    			++ones;
    		}
    		else{
    			++zeros;
    		}
    		if(ones>1){
    			return false;
    		}
    		num >>= 1;
    	}
    	if(zeros & 1){
    		return false;
    	}
    	return true;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().isPowerOfFour(3) << endl;;
	return 0;
}