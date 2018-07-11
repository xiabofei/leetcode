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
	int col_step[4] = {1, -1, 0, 0};
	int row_step[4] = {0, 0, -1, 1};
    bool exist(vector<vector<char>>& board, string word) {
    	if(board.size()==0){return false;}
    	if(board.size()*board[0].size()<word.size()){return false;}
    	for(int i = 0; i < board.size(); i++){
    		for(int j=0; j < board[0].size(); j++){
    			if(board[i][j]==word[0]){
    				board[i][j] = '.';
    				if(dfs(board, i, j, word, 1)){return true;}
    				board[i][j] = word[0];
    			}
    		}
    	}
    	return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string word, int curr){
    	if(curr==word.size()){return true;}
    	for(int s = 0; s < 4; s++){
    		int r = i + row_step[s];
    		int c = j + col_step[s];
    		if(
    			r>=0 && r<board.size() && c>=0 && c<board[0].size() &&  
    			board[r][c]!='.' && board[r][c]==word[curr]){
    			board[r][c] = '.';
    			if(dfs(board, r, c, word, curr+1)){return true;}
    			board[r][c] = word[curr];
    		}
    	}
    	return false;
    }
};