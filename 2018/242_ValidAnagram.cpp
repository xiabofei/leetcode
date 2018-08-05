#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
    	if(s.size()!=t.size()){return false;}
    	vector<int> alpha(26, 0);
    	for(int i=0; i<s.size(); i++){
    		alpha[s[i]-'a']++;
    		alpha[t[i]-'a']--;
    	}
    	for(int i=0; i<26; i++){
    		if(alpha[i]!=0){
    			return false;
    		}
    	}
    	return true;
    }
};