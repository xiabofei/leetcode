#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int min_price = INT_MAX;
    	int max_price = INT_MIN;
    	int profit = 0;
    	for(int i=0; i<prices.size(); i++){
    		min_price = min(min_price, prices[i]);
    		profit = max(profit, prices[i]-min_price);
    	}
    	return profit;
    }
};