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
    string shortestPalindrome(string s) {
    	string r = s;
    	reverse(r.begin(), r.end());
    	int l = s.size();
    	while(l>0){
    		if(s.substr(0, l)==r.substr(s.size()-l)){
    			break;
    		}
    		l--;
    	}
    	return r.substr(0, s.size()-l) + s;
    }
};