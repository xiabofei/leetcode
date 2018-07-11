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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size()==0 || matrix[0].size()==0){return false;}
    	int b = 0;
    	int e = matrix.size() * matrix.size() -1;
    	while(b<=e){
    		int m = (b+e)/2;
    		// 从全局个数考虑 增加一个row column编号转换
    		int r = m / matrix[0].size();
    		int c = m % matrix[0].size();
    		if(matrix[r][c]==target){
    			return true;
    		}
    		if(matrix[r][c]<target){
    			b = m + 1;
    		}
    		else{
    			e = m - 1;
    		}
    	}
    	return false;
    }
};