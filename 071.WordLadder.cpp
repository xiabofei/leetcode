#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, set<string>& wordDict)
    {
    	queue<string> curr;
    	queue<string> next;
    	int steps = 1;
    	if (beginWord!="") curr.push(beginWord);
    	while ( !curr.empty() )
    	{
    		while ( !curr.empty() )
    		{
    			string word = curr.front();
    			curr.pop();
    			for ( int i=0; i<word.size(); ++i )
    			{
    				for ( char c='a'; c<='z'; ++c )
    				{
    					if (word[i]==c) continue;
    					char ori = word[i];
    					word[i] = c;
    					if ( word==endWord ) return steps+1;
    					if ( wordDict.find(word)!=wordDict.end() )
    					{
    						next.push(word);
    						wordDict.erase(word);
    					}
    					word[i] = ori;
    				}
    			}
    		}
    		if ( !next.empty() )
    		{
    			steps++;
    			swap(curr, next);
    		}
    	}
    	return 0;
    }
};