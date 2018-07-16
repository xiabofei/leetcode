#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
    	if(timeSeries.size()==0){return 0;}
    	int total = duration;
    	int last_affect = timeSeries[0] + duration; 
    	for(int i=1; i<timeSeries.size(); i++){
    		if(last_affect > timeSeries[i]){
    			total +=  duration - (last_affect - timeSeries[i]);
    		}
    		else{
    			total += duration;
    		}
    		last_affect = timeSeries[i] + duration;
    	}
    	return total;
    }
};