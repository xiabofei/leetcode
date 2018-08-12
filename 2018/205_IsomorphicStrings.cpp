#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if(s.size()!=t.size()){return false;}
		unordered_map<char, char> m;
		unordered_set<char> used;
		for(int i=0; i<s.size(); i++){
			if(m.find(s[i])==m.end()){
				if(used.find(t[i])==used.end()){
					m[s[i]] = t[i];
					used.insert(t[i]);
				}
				else{
					return false;
				}
			}
			else{
				if(t[i]!=m[s[i]]){
					return false;
				}
			}
		}
		return true;
	}
};
