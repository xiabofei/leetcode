#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
1) 题干不要想复杂了 就是选两个棍 选好了之后 其余的棍就可以消失了 考察围住水的面积
2) 左右 短的往前或者后移动 因为 短的高度决定了高 由于是两边往中间逼近 所以短的遇到的就是它能遇到的最大长度 
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		if(height.size()<2) return 0;
		int l = 0;
		int r = height.size()-1;
		int max_area = 0;
		int curr_area = 0;
		while(l < r){
			curr_area = min(height[l], height[r]) * (r-l);
			if(curr_area > max_area){
				max_area = curr_area;
			}
			if(height[l] < height[r]){
				l++;
			}
			else{
				r--;
			}
		}
		return max_area;
	}
};