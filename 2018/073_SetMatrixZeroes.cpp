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
    void setZeroes(vector<vector<int>>& matrix) {
    	if(matrix.size()==0){return;}
    	const int row_size = matrix.size();
    	const int col_size = matrix[0].size();
    	// 记住第一行和第一列的flag
    	bool row_flag = false;
    	bool col_flag = false;
    	// 判断第一列是否有0
    	for(int r = 0; r < row_size; r++){
    		if(matrix[r][0]==0){
    			col_flag = true;
    			break;
    		}
    	}
    	// 判断第一行是否有0
    	for(int c = 0; c < col_size; c++){
    		if(matrix[0][c]==0){
    			row_flag = true;
    			break;
    		}
    	}
    	// 判断中间并记录在第一行和第一列
    	for(int r = 1; r < row_size; r++){
    		for(int c = 1; c < col_size; c++){
    			if(matrix[r][c]==0){
    				matrix[r][0] = 0;
    				matrix[0][c] = 0;
    			}
    		}
    	}
    	// 中间行置零
    	for(int r = 1; r < row_size; r++){
    		if(matrix[r][0]==0){
    			for(int c = 1; c < col_size; c++){
    				matrix[r][c] = 0;
    			}
    		}
    	}
    	// 中间列置零
    	for(int c = 1; c < col_size; c++){
    		if(matrix[0][c]==0){
    			for(int r = 1; r < row_size; r++){
    				matrix[r][c] = 0;
    			}
    		}
    	}
    	// 第一列 第一行
    	if(row_flag){
    		for(int c = 0; c < col_size; c++){ matrix[0][c]=0; }
    	}
    	if(col_flag){
    		for(int r = 0; r < row_size; r++){ matrix[r][0]=0; }
    	}
    }
};