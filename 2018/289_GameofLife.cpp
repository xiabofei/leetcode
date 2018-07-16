#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 题意好理解 难点在in-place完成状态更新
// https://segmentfault.com/a/1190000003819277
// 采用编码和bit操作
// 第二个bit代表本轮状态  第一个bit代表下轮状态
// dead from dead : 00 → 0
// dead from live : 01 → 1 
// live from dead : 10 → 2 
// live from live : 11 → 3
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
    	const int row_num = board.size();
    	if(row_num==0){return;}
    	const int col_num = board[0].size();
    	for(int r = 0; r < row_num; r++){
    		for(int c = 0; c < col_num; c++){
    			int live_cnts = 0;
    			// 扫描周围8个邻居 并考虑corner情况
    			for(int rr = max(r-1,0); rr <= min(r+1, row_num-1); rr++){
    				for(int cc = max(c-1,0); cc <= min(c+1, col_num-1); cc++){
    					live_cnts += board[rr][cc] & 1;
    				}
    			}
    			// 下一轮生死 直接第二个bit置位
    			if(live_cnts==3 || live_cnts - board[r][c] == 3){
    				board[r][c] |= 2;
    			}
    		}
    	}
    	// 全扫描 恢复01
    	for(int r=0; r<row_num; r++){
    		for(int c=0; c<col_num; c++){
    			board[r][c] >>= 1 ;
    		}
    	}
    }
};