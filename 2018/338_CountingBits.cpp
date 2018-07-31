#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/5294255.html
// 上述的解法三 one-pass 利用了dp思想
// 如果n是奇数 比上一个偶数多了最后一个1
// 如果n是偶数 最后一位是0 与n/2的1bits个数一样( 移位运算与乘除法关系 n*2与n<<1效果一样)

class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> ret;
    	ret.push_back(0);
    	for(int n=1; n<=num; n++){
    		if(n&1){
    			// n是奇数
    			// ret.push_back(ret[n/2]+1);
    			ret.push_back(ret[n-1]+1);
    		}
    		else{
    			// n是偶数
    			ret.push_back(ret[n/2]);
    		}
    	}
    	return ret;
    }
};