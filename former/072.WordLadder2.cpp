#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(
    	string start, string end, set<string> &dict)
    {
    	vector<vector<string> > ret;
    	map<string, vector<string> > word_pre;
    	bool found = false;
    	queue<string> curr;
    	queue<string> next;
    	if ( start!="" ) curr.push(start);
    	while ( !curr.empty() )
    	{
    		set<string> usedThisStep;
    		while ( !curr.empty() )
    		{
    			string word = curr.front();
    			string thisStep = word;
    			curr.pop();
    			for ( int i=0; i<word.size(); ++i )
    			{
    				char ori = word[i];
    				for ( char c='a'; c<='z'; ++c )
    				{
    					if (word[i]==c) continue;
    					word[i] = c;
    					if ( word==end )
    					{
    						word_pre[end].push_back(thisStep);
    						found = true;
    						word[i] = ori;
    						break;
    					}
    					if ( dict.find(word)!=dict.end() )
    					{
    						word_pre[word].push_back(thisStep);
    						usedThisStep.insert(word);
    					}
    					word[i] = ori;
    				}
    			}
    		}
    		if ( !found ) 
    		{
    			for ( set<string>::iterator i=usedThisStep.begin(); i!=usedThisStep.end(); ++i )
    			{
    				next.push(*i);
    				dict.erase(*i);
    			}
    			swap(curr, next);
    		}
    		else
    		{
    			break;
    		}
    	}
    	if (!found) return ret;
    	vector<string> tmp;
    	tmp.push_back(end);
    	Solution::dfs(word_pre, tmp, end, ret, start);
    	return ret;
    }
    static void dfs(map<string, vector<string> >& word_pre, 
    	vector<string>& tmp, string word, vector<vector<string> >& ret, string start)
    {
    	if ( word==start )
    	{
    		reverse(tmp.begin(), tmp.end());
    		ret.push_back(tmp);
    		reverse(tmp.begin(), tmp.end());
    		return;
    	}
    	for ( int i=0; i<word_pre[word].size(); ++i )
    	{
    		tmp.push_back(word_pre[word][i]);
    		Solution::dfs(word_pre, tmp, word_pre[word][i], ret, start);
    		tmp.pop_back();
    	}
    }
};