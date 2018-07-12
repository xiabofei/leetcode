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
    int largestRectangleArea(vector<int>& heights) {
    	if(heights.size()==0){return 0;}
    	// 记录某个位置向left和right最大的
    	vector<int> dp_l(heights.size(), 0);
    	vector<int> dp_r(heights.size(), heights.size()-1);
    	// 最左边走到哪
    	for(int i = 1; i < heights.size(); i++){
    		int l = i;
    		while(l>0 && heights[i] <= heights[l-1]){
    			l = dp_l[l-1];
    		}
    		dp_l[i] = l;
    	}
    	// 最右边走到哪
    	for(int i = heights.size()-2; i>=0; i--){
    		int r = i;
    		while(r<heights.size()-1 && heights[i]<=heights[r+1]){
    			r = dp_r[r+1];
    		}
    		dp_r[i] = r;
    	}
    	// 获得最大值
    	int largest = 0;
    	for(int i = 0; i < heights.size(); i++){
    		int l = dp_l[i];
    		int r = dp_r[i];
    		int h = heights[i];
    		largest = max(largest, (r-l+1)*h);
    	}
    	return largest;
    }
};