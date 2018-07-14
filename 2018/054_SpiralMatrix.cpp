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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ret;
    	if(matrix.size()==0){return ret;}
    	// 设定每轮四个角的坐标范围
    	int r1 = 0;
    	int r2 = matrix.size()-1;
    	int c1 = 0;
    	int c2 = matrix[0].size()-1;
    	while(r1<=r2 && c1<=c2){
    		// up row
    		for(int i=c1; i<=c2; i++){
    			ret.push_back(matrix[r1][i]);
    		}
    		// left column
    		for(int i=r1+1; i<=r2; i++){
    			ret.push_back(matrix[i][c2]);
    		}
    		// bottom row
    		if(r1!=r2){
    			for(int i=c2-1; i>=c1; i--){
    				ret.push_back(matrix[r2][i]);
    			}
    		}
    		// left column
    		if(c1!=c2){
    			for(int i=r2-1; i>=r1+1; i--){
    				ret.push_back(matrix[i][c1]);
    			}
    		}
    		r1++;
    		r2--;
    		c1++;
    		c2--;
    	}
    	return ret;
    }
};