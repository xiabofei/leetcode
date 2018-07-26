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
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const int rows = matrix.size();
        if(rows==0){return false;}
        const int cols = matrix[0].size();
        for(int r=0; r<rows; r++){
        	int x = r; 
        	int y = 0;
        	int val = matrix[x][y];
        	while(x<rows && y<cols){
        		if(matrix[x++][y++]!=val){return false;}
        	}
        }
        for(int c=1; c<cols; c++){
        	int x = 0;
        	int y = c;
        	int val = matrix[x][y];
        	while(x<rows && y<cols){
        		if(matrix[x++][y++]!=val){return false;}
        	}
        }
        return true;
    }
};