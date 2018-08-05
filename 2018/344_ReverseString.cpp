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
    string reverseString(string s) {
    	for(int i=0; i<s.size()/2; i++){
    		swap(s[i], s[s.size()-1-i]);
    	}
    	return s;
    }
};