#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word)
    {
    	for ( int i=0; i<board.size(); ++i )
    	{
    		for ( int j=0; j<board[i].size(); ++j )
    		{
    			if ( board[i][j]==word[0] )
    			{
    				board[i][j] = '#';
    				if (Solution::dfs(board, i, j, word.substr(1, word.size()-1))) return true;
    				board[i][j] = word[0];
    			}
    		}
    	}
    	return false;
    }
    static bool dfs(vector<vector<char> >& board, int r, int c, string word)
    {
    	if (word=="") return true;
    	// left
    	if ( c-1>=0 && board[r][c-1]==word[0] )
    	{
    		board[r][c-1] = '#';
    		if (Solution::dfs(board, r, c-1, word.substr(1, word.size()-1))) return true;
    		board[r][c-1] = word[0];
    	}
    	// right
    	if ( c+1<board[0].size() && board[r][c+1]==word[0] )
    	{
    		board[r][c+1] = '#';
    		if (Solution::dfs(board, r, c+1, word.substr(1, word.size()-1))) return true;
    		board[r][c+1] = word[0];
    	}
    	// up
    	if ( r-1>=0 && board[r-1][c]==word[0] )
    	{
    		board[r-1][c] = '#';
    		if (Solution::dfs(board, r-1, c, word.substr(1,word.size()-1))) return true;
    		board[r-1][c] = word[0];
    	}
    	// down
    	if ( r+1<board.size() && board[r+1][c]==word[0] )
    	{
    		board[r+1][c] = '#';
    		if (Solution::dfs(board, r+1, c, word.substr(1,word.size()-1))) return true;
    		board[r+1][c] = word[0];
    	}
    	return false;
    }
};