#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// ugly number就是维护多个序列
// 属于ugly number II的扩展版
// 维护n+1个list
// '1'指的是历史ugly number的序列
// 'n'指的是n个primes的index序列

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
    	vector<int> indexes(primes.size(), 0);
    	vector<int> dp;
    	dp.push_back(1);
    	while(dp.size()<n){
    		// 计算每轮的最小值
    		int curr_min = INT_MAX;
    		for(int i=0; i<primes.size(); i++){
    			curr_min = min(curr_min, dp[indexes[i]]*primes[i]) ;
    		}
    		dp.push_back(curr_min);
    		// 更新各个index
    		for(int i=0; i<indexes.size(); i++){
    			if(curr_min==dp[indexes[i]]*primes[i]){
    				indexes[i]++;
    			}
    		}
    	}
    	return dp.back();
    }
};