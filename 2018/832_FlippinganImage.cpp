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
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
    	vector<vector<int>> ret(A.size(), vector<int>(A[0].size(), 0));
    	const int rows = A.size();
    	const int cols = A[0].size();
    	// 水平翻转
    	for(int r=0; r<rows; r++){
    		for(int c=0; c<cols; c++){
    			ret[r][c] = A[r][cols-1-c];
    		}
    	}
    	// 01互换
    	for(int r=0; r<rows; r++){
    		for(int c=0; c<cols; c++){
    			ret[r][c] = (ret[r][c]==1 ? 0 : 1); 
    		}
    	}
    	return ret;
    }
};
