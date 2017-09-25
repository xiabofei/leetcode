#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board)
    {
    	const int m = board.size();
    	const int n = board[0].size();
    	// first row
    	for ( int i=0; i<n; ++i )
    	{
    		if (board[0][i]=='O') Solution::bfs(board, 0, i);
    	}
    	// first column
    	for ( int i=0; i<m; ++i )
    	{
    		if (board[i][0]=='O') Solution::bfs(board, i, 0);
    	}
    	// last row
    	for ( int i=0; i<n; ++i )
    	{
    		if (board[m-1][i]=='O') Solution::bfs(board, m-1, i);
    	}
    	// last column
    	for ( int i=0; i<m; ++i )
    	{
    		if (board[i][n-1]=='O') Solution::bfs(board, i, n-1);
    	}
    	// traversal
    	for ( int i=0; i<m; ++i )
    	{
    		for ( int j=0; j<n; ++j )
    		{
    			if (board[i][j]=='M')
    				board[i][j]='O';
    			else
    				board[i][j]='X';
    		}
    	}
    }
    static void bfs(vector<vector<char> >& board, int i, int j)
    {
    	board[i][j] = 'M';
    	queue<pair<int, int> > curr;
    	queue<pair<int, int> > next;
    	curr.push(make_pair(i, j));
    	while ( !curr.empty() )
    	{
    		while ( !curr.empty() )
    		{
    			int r = curr.front().first;
    			int c = curr.front().second;
    			curr.pop();
    			// left
    			if ( c-1>=0 && board[r][c-1]=='O' )
    			{
    				board[r][c-1] = 'M'; 
    				next.push(make_pair(r, c-1));
    			}
    			// right
    			if ( c+1<board[0].size() && board[r][c+1]=='O' )
    			{
    				board[r][c+1] = 'M';
    				next.push(make_pair(r, c+1));
    			}
    			// up
    			if ( r-1>=0 && board[r-1][c]=='O' )
    			{
    				board[r-1][c] = 'M';
    				next.push(make_pair(r-1, c));
    			}
    			// down
    			if ( r+1<board.size() && board[r+1][c]=='O' )
    			{
    				board[r+1][c] = 'M';
    				next.push(make_pair(r+1, c));
    			}
    		}
    		swap(curr, next);
    	}
    }
};