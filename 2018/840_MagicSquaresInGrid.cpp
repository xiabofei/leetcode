#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://leetcode.com/problems/magic-squares-in-grid/discuss/143797/simple-C++-solutions-with-some-explanation
// 5必须是中间点
class Solution {
public:
	int numMagicSquaresInside(vector<vector<int>>& grid) {
		const int R = grid.size();
		if(R<3){return 0;}
		const int C = grid[0].size();
		if(C<3){return 0;}
    	// 遍历中心点 以5为中心
    	// 每行 每列 斜对角 必须和都是15
    	// 1-9的和是45
		int ret= 0; 
		for(int r=1; r<R-1; r++){
			for(int c=1; c<C-1; c++){
				if(grid[r][c]==5 && isValid(grid, r, c)){
					ret++;
				}
			}
		}
		return ret;
	}
	bool isValid(vector<vector<int>>& g, int r, int c){
    	// rows
		for(int i=r-1; i<=r+1; i++){
			int sum = 0;
			for(int j=c-1; j<=c+1; j++){
				if(g[i][j]<=0 || g[i][j]>9){
					return false;
				}
				sum += g[i][j];
			}
			if(sum!=15){
				return false;
			}
		}
    	// columns
		for(int i=c-1; i<=c+1; i++){
			int sum = 0;
			for(int j=r-1; j<=r+1; j++){
				sum += g[j][i];
			}
			if(sum!=15){
				return false;
			}
		}
    	// left top → right bottom
		if(g[r-1][c-1]+g[r+1][c+1]!=10){return false;}
		if(g[r-1][c+1]+g[r+1][c-1]!=10){return false;}
		return true;
	}
};