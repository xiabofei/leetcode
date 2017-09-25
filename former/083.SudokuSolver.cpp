#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> >& board)
    {
    	vector<pair<int, int> > blank;
    	for ( int i=0; i<9; ++i )
    	{
    		for ( int j=0; j<9; ++j )
    		{
    			if (board[i][j]=='.') blank.push_back(make_pair(i, j));
    		}
    	}
    	Solution::dfs(board, blank);
    }
    static bool dfs(vector<vector<char> >& board, vector<pair<int, int> >& blank)
    {
    	if ( blank.empty() ) return true;
    	const int r = blank.back().first;
    	const int c = blank.back().second;
    	for ( char v='1'; v<='9'; ++v )
    	{
    		int valid = true;
    		for ( int i=0; i<9; ++i )
    		{
    			if ( board[r][i]==v || board[i][c]==v || board[i/3+(r/3)*3][i%3+(c/3)*3]==v )
    			{
    				valid = false;
    				break;
    			}
    		}
    		if ( valid )
    		{
    			board[r][c] = v;
    			blank.pop_back();
    			if (Solution::dfs(board, blank)) return true;
    			blank.push_back(make_pair(r, c));
    			board[r][c] = '.';
    		}
    	}
    	return false;
    }
};