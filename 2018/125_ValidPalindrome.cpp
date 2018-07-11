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
    bool isPalindrome(string s){
    	if(s.size()<2){return true;}
    	transform(s.begin(), s.end(), s.begin(), ::tolower);
    	int phead = 0;
    	int ptail = s.size()-1;
    	// while循环里面每次动一个指针(要么phead 要么ptail 一起动就不好写)
    	while(phead<ptail){
    		if(!isalnum(s[phead])){
    			phead++;
    		}
    		else if(!isalnum(s[ptail])){
    			ptail--;
    		}
    		else if(s[phead]!=s[ptail]){
    			return false;
    		}
    		else{
    			phead++;
    			ptail--;
    		}
    	}
    	return true;
    }
};