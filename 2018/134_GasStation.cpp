#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// total>=0
// 每次遇到负数就默认下一个是start位置

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    	const int len = gas.size();
    	if(len==0){return 0;}
    	int start = 0;
    	int sum = 0;
    	int total = 0;
    	for(int i=0; i<len; i++){
    		sum += gas[i]-cost[i];
    		if(sum<0){
    			total += sum;
    			sum = 0;
    			start = i+1;
    		}
    	}
    	total += sum;
    	return total<0 ? -1 : start;
    }
};