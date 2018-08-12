#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// http://www.cnblogs.com/grandyang/p/4682458.html
// 类比 Unique Binary Search Tree II

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
    	vector<int> ret;
    	for(int i=0; i<input.size(); i++){
    		char c = input[i];
    		if(c=='-' || c=='+' || c=='*'){
    			vector<int> left = diffWaysToCompute(input.substr(0, i));
    			vector<int> right = diffWaysToCompute(input.substr(i+1));
    			for(int l=0; l<left.size(); l++){
    				for(int r=0; r<right.size(); r++){
    					int tmp = 0;
    					if(c=='+'){
    						tmp = left[l] + right[r];
    					}
    					else if(c=='-'){
    						tmp = left[l] - right[r];
    					}
    					else{
    						tmp = left[l] * right[r];
    					}
    					ret.push_back(tmp);
    				}
    			}
    		}
    	}
    	if(ret.empty()){
    		ret.push_back(atoi(input.c_str()));
    	}
    	return ret;
    }
};
