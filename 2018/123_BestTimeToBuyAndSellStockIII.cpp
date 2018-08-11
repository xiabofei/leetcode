#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// dp_global : 讨论点'最后一次交易是否在当天完成'
// dp_local : 最后一次交易在当天完成获得的最大利润

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int days = prices.size();
    	if(days<2){return 0;}
    	int trans = 2;
    	int dp_global[days][trans+1];
    	int dp_local[days][trans+1];
    	fill_n(&dp_global[0][0], days*(trans+1), 0);
    	fill_n(&dp_local[0][0], days*(trans+1), 0);
    	for(int d=1; d<days; d++){
    		int tmp_profit = prices[d]-prices[d-1];
    		for(int t=1; t<=trans; t++){
    			dp_local[d][t] = max(
                    dp_global[d-1][t-1]+max(tmp_profit, 0), 
                    dp_local[d-1][t]+tmp_profit
                    );
    			dp_global[d][t] = max(dp_local[d][t], dp_global[d-1][t]);
    		}
    	}
    	return dp_global[days-1][trans];
    }
};