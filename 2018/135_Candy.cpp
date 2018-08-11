#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// greedy思路
// left to right保证一遍
// right to left保证一遍

class Solution {
public:
    int candy(vector<int>& ratings) {
    	if(ratings.size()==0){return 0;}
    	vector<int> cands(ratings.size(), 1);
    	// left to right 
    	for(int i=1; i<ratings.size(); i++){
    		if(ratings[i] > ratings[i-1]){
    			cands[i] = cands[i-1]+1;
    		}
    	}
    	// right to left
    	for(int i=ratings.size()-2; i>=0; i--){
    		if(ratings[i] > ratings[i+1]){
    			cands[i] = max(cands[i+1]+1, cands[i]);
    		}
    	}
    	// sum
    	int ret = 0;
    	for(int i=0; i<cands.size(); i++){
    		ret += cands[i];
    	}
    	return ret;
    }
};