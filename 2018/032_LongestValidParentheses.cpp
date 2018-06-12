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
    int longestValidParentheses(string s) {
    	stack<int> sta;
    	int longest = 0;
    	int last_pos = -1;
    	for(int i=0; i<s.size(); i++){
    		if(s[i]=='('){
    			sta.push(i);
    		}
    		else{
    			if(sta.empty()){
    				last_pos = i;
    			}
    			else{
    				sta.pop();
    				if(sta.empty()){
    					longest = max(longest, i - last_pos);
    				}
    				else{
    					longest = max(longest, i - sta.top());
    				}
    			}
    		}
    	}
    	return longest;
    }
};