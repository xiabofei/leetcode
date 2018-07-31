#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// https://blog.csdn.net/xudli/article/details/46798619
// 思路 : 统计10位的1  100位的1 1000位的1
// 比如 统计百分位上的1 分三种情况 0/1/其他
// 5092 → 5*100
// 5192 → 5*100+92+1
// 5292 → 5*100+100

class Solution {
public:
    int countDigitOne(int n) {
    	int ret = 0;
    	for(long m=1; n/m>0; m *= 10){
    		long high = n/m;
    		long remainder = n%m;
    		ret += high/10*m;
    		if(high%10==1){
    			ret += remainder + 1;
    		}
    		else if(high%10>1){
    			ret += m;
    		}
    	}
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	int n = 5092;
	Solution().countDigitOne(n);
	return 0;
}