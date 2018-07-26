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
    vector<int> constructArray(int n, int k) {
    	vector<int> ret;
    	int small = 1;
    	int large = n;
    	while(small<=large){
    		if(k==1){
    			ret.push_back(small);
    			small++;
    		}
    		else{
    			if(k&1){
    				ret.push_back(small++);
    			}
    			else{
    				ret.push_back(large--);
    			}
    			k--;
    		}
    	}
    	return ret;
    }
};