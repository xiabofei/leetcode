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
	vector<vector<int>> directs = {{0,1},{0,-1},{1,0},{-1,0}};
    int numIslands(vector<vector<char>>& grid) {
    	const int row_num = grid.size();
    	if(row_num==0){return 0;}
    	const int col_num = grid[0].size();
    	int island_cnts = 0;
    	for(int r = 0; r < row_num; r++){
    		for(int c = 0; c < col_num; c++){
    			if(grid[r][c]=='1'){
    				island_cnts++;
    				grid[r][c] = 'n';
    				queue<pair<int,int>> q;
    				q.push({r,c});
    				while(!q.empty()){
    					int curr_r = q.front().first;
    					int curr_c = q.front().second;
    					q.pop();
    					// 遍历四个方向
    					for(int d = 0; d < directs.size(); d++){
    						int next_r = curr_r + directs[d][0];
    						int next_c = curr_c + directs[d][1];
    						// 越界
    						if(next_r<0 || next_r>=row_num || next_c<0 || next_c>=col_num){
    							continue;
    						}
    						// 访问过 或是水
    						if(grid[next_r][next_c]!='1'){
    							continue;
    						}
    						grid[next_r][next_c] = 'n';
    						q.push({next_r, next_c});
    					}
    				}
    			}
    		}
    	}
    	return island_cnts;
    }
};