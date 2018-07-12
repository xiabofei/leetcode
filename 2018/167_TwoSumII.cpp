#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std	;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    	vector<int> ret;
    	int l = 0;
    	int r = numbers.size()-1;
    	while(l<r){
    		int tmp = numbers[l] + numbers[r];
    		if(tmp == target){
    			ret.push_back(l+1);
    			ret.push_back(r+1);
    			break;
    		}
    		else if(tmp < target){
    			l++;
    		}
    		else{
    			r--;
    		}
    	}
    	return ret;
    }
};