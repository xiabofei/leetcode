#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std ;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
    	const int row_num = matrix.size();
    	if(row_num==0){return 0;}
    	const int col_num = matrix[0].size();

    	// 以每个row为底的histogram的高度
    	vector<vector<int>> height(row_num, vector<int>(col_num, 0));
    	for(int c = 0; c < col_num; c++){
    		height[0][c] = matrix[0][c]=='0' ? 0 : 1;
    	}
    	for(int r = 1; r < row_num; r++){
    		for(int c = 0; c < col_num; c++){
    			if(matrix[r][c]!='0'){
    				height[r][c] = height[r-1][c] + 1;
    			}
    		}
    	}
    	// 以每个row为低 求最大的rectangle historgram
    	int ret = 0;
    	for(int r = 0; r < row_num; r++){
    		ret = max(ret, historgram(height[r]));
    	}
    	return ret;
    }
    int historgram(vector<int>& height){
    	if(height.size()==1){
    		return height[0];
    	}
    	vector<int> dp_left(height.size(), 0);
    	vector<int> dp_right(height.size(), height.size()-1);
    	// 求左侧最远到达的位置
    	for(int i=1; i<height.size(); i++){
    		int p = i;
    		while(p>0 && height[i]<=height[p-1]){p = dp_left[p-1];}
    		dp_left[i] = p;
    	}
    	// 求右侧最远到达位置
    	for(int i=height.size()-2; i>=0; i--){
    		int p = i;
    		while(p<height.size()-1 && height[i]<=height[p+1]){p = dp_right[p+1];}
    		dp_right[i] = p;
    	}
    	// 扫描 获得最大面积
    	int ret = 0;
    	for(int i=0; i<height.size(); i++){
    		int l = dp_left[i];
    		int r = dp_right[i];
    		int h = height[i];
    		ret = max(ret, (r-l+1)*h);
    	}
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	vector<vector<char>> data;
	vector<char> tmp0 = {'1', '0', '1', '0', '0'};
	data.push_back(tmp0);
	vector<char> tmp1 = {'1', '0', '1', '1', '1'};
	data.push_back(tmp1);
	vector<char> tmp2 = {'1', '1', '1', '1', '1'};
	data.push_back(tmp2);
	vector<char> tmp3 = {'1', '0', '0', '1', '0'};
	data.push_back(tmp3);
	Solution().maximalRectangle(data);
	return 0;
}