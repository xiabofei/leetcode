#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>

using namespace std;


// https://www.cnblogs.com/yrbbest/p/5005947.html
// 从右上角开始找 比目标值大column-1 比目标值小row+1

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	const int rows = matrix.size();
    	if(rows==0){return false;}
    	const int cols = matrix[0].size();
    	if(cols==0){return false;}
    	if(target<matrix[0][0] || target>matrix[rows-1][cols-1]){return false;}
    	int r = 0, c = cols-1;
    	while(r<rows && c>=0){
    		if(matrix[r][c]==target){
    			return true;
    		}
    		else if(matrix[r][c]>target){
    			c--;
    		}
    		else{
    			r++;
    		}
    	}
    	return false;
    }
};