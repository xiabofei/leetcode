#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/7776979.html

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
    	if(prices.size()<2){return 0;}
    	// 第i天手头没股票profit
    	vector<int> sold(prices.size(), 0);
    	// 第i天手头有股票profit
    	vector<int> hold(prices.size(), 0);
    	hold[0] = -prices[0];
    	for(int i = 1; i<prices.size(); i++){
    		sold[i] = max(sold[i-1], hold[i-1] + prices[i] - fee);
    		hold[i] = max(hold[i-1], sold[i-1] - prices[i]);
    	}
    	return sold[prices.size()-1];
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	Solution().maxProfit(dat, 2);
	return 0;
}