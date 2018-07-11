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
    int maxArea(vector<int>& height) {
    	int l = 0;
    	int r = height.size()-1;
    	int global = INT_MIN;
    	// 有个误区 : 每次抽出left和right即可(不用管中间的)
    	// 双指针保证每个bar作为'高' 能够到的最大'长
    	while(l<r){
    		if(height[l] < height[r]){
    			global = max(global, (r-l) * height[l]);
    			l++;
    		}
    		else{
    			global = max(global, (r-l) * height[r]);
    			r--;
    		}
    	}
    	return global;
    }
};