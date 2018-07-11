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
    bool validPalindrome(string s) {
    	if(s.size()<3){return true;}
    	int l = 0;
    	int r = s.size()-1;
    	bool already_delete = false;
    	while(l<r){
    		if(s[l]==s[r]){l++; r--;}
    		else{
    			return isPalindrome(s, l+1, r) || isPalindrome(s, l, r-1);
    		}
    	}
    	return true;
    }
    bool isPalindrome(string s, int l, int r){
    	while(l<r){
    		if(s[l]!=s[r]){return false;}
    		l++;
    		r--;
    	}
    	return true;
    }
};