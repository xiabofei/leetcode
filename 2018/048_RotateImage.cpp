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
    void rotate(vector<vector<int>>& matrix) {
    	if(matrix.size()==0){return;}
    	const int n = matrix.size();
    	// 先沿着down left和up right的对角线交换元素
    	for(int r=0; r<n-1; r++){
    		for(int c=0; c<n-r-1; c++){
    			swap(matrix[r][c], matrix[n-1-c][n-1-r]);
    		}
    	}
    	// 再沿着中轴线交换上下对应元素
    	int m = n/2;
    	for(int r=0; r<m; r++){
    		for(int c=0; c<n; c++){
    			swap(matrix[r][c], matrix[n-1-r][c]);
    		}
    	}
    }
};