#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> row_d = {0, 0, -1, 1};
	vector<int> col_d = {-1, 1, 0, 0};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    	if(grid.size()==0){return 0;}
    	int max_area = 0;
    	const int row_num = grid.size();
    	const int col_num = grid[0].size();
    	for(int r=0; r<row_num; r++){
    		for(int c=0; c<col_num; c++){
    			if(grid[r][c]!=1){continue;}
    			queue<pair<int,int>> q;
    			q.push({r,c});
    			int cnt = 0;
    			// -1为已经访问状态 只要是访问过的点 就不需要再访问了 因为bfs保证只要是连同的都能访问到
    			grid[r][c] = -1;
    			while(!q.empty()){
    				int curr_r = q.front().first;
    				int curr_c = q.front().second;
    				q.pop();
    				max_area = max(max_area, ++cnt);
    				// 遍历四个方向
    				for(int d=0; d<4; d++){
    					int next_r = curr_r + row_d[d];
    					int next_c = curr_c + col_d[d];
    					if(next_r<0 || next_r>=row_num || next_c<0 || next_c>=col_num){
    						continue;
    					}
    					if(grid[next_r][next_c]<=0){continue;}
    					grid[next_r][next_c] = -1; 
    					q.push({next_r, next_c});
    				}
    			}
    		}
    	}
    	return max_area;
    }
};
