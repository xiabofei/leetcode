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
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
    	vector<vector<int>> ret;
    	const int r_curr = nums.size();
    	if(r_curr==0 || r*c != r_curr*nums[0].size()){return nums;}
    	const int c_curr = nums[0].size();
    	// 维护一个计数变量 累计加到r就换行
    	vector<int> row;
    	for(int i=0; i<r_curr; i++){
    		for(int j=0; j<c_curr; j++){
    			if(row.size()==c){
    				ret.push_back(row);
    				row.clear();
    			}
    			row.push_back(nums[i][j]);
    		}
    	}
    	if(!row.empty()){
    		ret.push_back(row);
    	}
    	return ret;
    }
};