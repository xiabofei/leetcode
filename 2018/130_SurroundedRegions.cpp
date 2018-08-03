#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
	vector<pair<int,int>> directs = {{0,-1},{0,1},{1,0},{-1,0}};
    void solve(vector<vector<char>>& board) {
    	const int rows = board.size();
    	if(rows==0){return;}
    	const int cols = board[0].size();
    	// 从四个边界上的'O'出发 发现'O'置换为'Z'
    	// top and bottom
    	for(int i=0; i<cols; i++){
    		if(board[0][i]=='O'){bfs(board, 0, i, rows, cols);}
    		if(board[rows-1][i]=='O'){bfs(board, rows-1, i, rows, cols);}
    	}
    	// left and right
    	for(int i=0; i<rows; i++){
    		if(board[i][0]=='O'){bfs(board, i, 0, rows, cols);}
    		if(board[i][cols-1]=='O'){bfs(board, i, cols-1, rows, cols);}
    	}
    	// 扫描矩阵 替换'Z'为'O' ''
    	for(int r=0; r<rows; r++){
    		for(int c=0; c<cols; c++){
    			if(board[r][c]=='O'){
    				board[r][c]='X';
    			}
    			else if(board[r][c]=='Z'){
    				board[r][c]='O';
    			}
    		}
    	}
    }
    void bfs(
    	vector<vector<char>>& b, int r, int c, 
    	const int rows, const int cols){
    	queue<pair<int,int>> q;
    	b[r][c] = 'Z';
    	q.push({r, c});
    	// 把与边界能连接到的'O'都置换为'Z'
    	while(!q.empty()){
    		int row = q.front().first;
    		int col = q.front().second;
    		q.pop();
    		for(int i=0; i<4; i++){
    			int rr = row+directs[i].first;
    			int cc = col+directs[i].second;
    			if(rr>0 && rr<rows && cc>0 && cc<cols && b[rr][cc]=='O'){
    				b[rr][cc] = 'Z';
    				q.push({rr, cc});
    			}
    		}
    	}
    }
};