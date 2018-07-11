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
    	int total_profit = 0;
    	int tmp_profit = 0;
    	for(int i=1; i<prices.size(); i++){
    		if(prices[i]>prices[i-1]){
    			tmp_profit += prices[i] - prices[i-1];
    		}
    		else{
    			total_profit += tmp_profit;
    			tmp_profit = 0;
    		}
    	}
    	total_profit += tmp_profit;
    	return total_profit;
    }
};