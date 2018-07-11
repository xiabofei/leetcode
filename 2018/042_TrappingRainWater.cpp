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
    int trap(vector<int>& height) {
    	if(height.size()<3){return 0;}
    	int l_bars[height.size()];
    	fill_n(&l_bars[0], height.size(), 0);
    	int r_bars[height.size()];
    	fill_n(&r_bars[0], height.size(), 0);

    	// 每个bar能顶多少水 由两个因素决定
    	// 1) left的最高bar
    	// 2) right的最高bar
    	// 1)和2)的最小值决定
    	int l_max = height[0];
    	for(int i=1; i<height.size()-1; i++){
    		l_max = max(l_max, height[i]);
    		l_bars[i] = l_max;
    	}
    	int r_max = height[height.size()-1];
    	for(int i=height.size()-2; i>0; i--){
    		r_max = max(r_max, height[i]);
    		r_bars[i] = r_max;
    	}
    	int ret = 0;
    	for(int i=1; i<height.size()-1; i++){
    		ret += max(min(l_bars[i], r_bars[i]) - height[i], 0);
    	}
    	return ret;
    }
};