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
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
    	const int row_num = M.size();
    	if(row_num==0){return M;}
    	const int col_num = M[0].size();
    	vector<vector<int>> ret(row_num, vector<int>(col_num, 0));
    	for(int r=0; r<row_num; r++){
    		for(int c=0; c<col_num; c++){
    			// 遍历周围像素点
    			int sum = 0;
    			int cnt = 0;
    			for(int rr=max(0, r-1); rr<=min(r+1,row_num-1); rr++){
    				for(int cc=max(0, c-1); cc<=min(c+1, col_num-1); cc++){
    					sum += M[rr][cc];
    					cnt++;
    				}
    			}
    			ret[r][c] = floor(sum/double(cnt));
    		}
    	}
    	return ret;
    }
};