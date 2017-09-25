#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board)
    {
    	for ( int i=0; i<board.size(); ++i )
    	{
    		// check row
    		vector<bool> row(9, false);
    		for ( int j=0; j<9; ++j )
    		{
    			if (board[i][j]=='.') continue;
    			if ( !row[board[i][j]-'1'] )
    			{
    				row[board[i][j]-'1'] = true;
    			}
    			else
    			{
    				return false;
    			}
    		}
    		// chec column
    		vector<bool> col(9, false);
    		for ( int j=0; j<9; ++j )
    		{
    			if (board[j][i]=='.') continue;
    			if ( !col[board[j][i]-'1'] )
    			{
    				col[board[j][i]-'1'] = true;
    			}
    			else
    			{
    				return false;
    			}
    		}
    		// check matrix
    		vector<bool> matrix(9, false);
    		for ( int j=0; j<9; ++j )
    		{
    			int r = 3*(i/3) + j/3;
    			int c = 3*(i%3) + j%3;
    			if (board[r][c]=='.') continue;
    			if ( !matrix[board[r][c]-'1'] )
    			{
    				matrix[board[r][c]-'1'] = true;	
    			}
    			else
    			{
    				return false;
    			}
    		}
    	}
    	return true;
    }
};