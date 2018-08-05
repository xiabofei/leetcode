#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// https://soulmachine.gitbooks.io/algorithm-essentials/java/dp/best-time-to-buy-and-sell-stock-with-cooldown.html
// sell[i] 表示第i天手上没stock状态的 max profit
// buy[i] 表示第i天手上持有stock状态的 max profit
// sell[i] = max(sell[i-1], buy[i-1]+price) i-1天手里就没股票了 或 i-1处于持有股票 第i天卖了
// buy[i] = max(buy[i-1], sell[i-2]-price) i-1天手里就持有股票了 或 i-1天是cooldown状态(i-2天时候卖了) 第i天买入

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()==0){return 0;}
    	int buy = -prices[0];
    	int sell = 0;
    	int pre_sell = 0;
    	for(int i=1; i<prices.size(); i++){
    		int tmp = sell;
    		sell = max(sell, buy+prices[i]);
    		buy = max(buy, pre_sell-prices[i]);
    		pre_sell = tmp;
    	}
    	return sell;
    }
};