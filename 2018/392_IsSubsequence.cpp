#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://blog.csdn.net/MebiuW/article/details/52444480
// 是否是子串 双指针一起移动

class Solution {
public:
    bool isSubsequence(string s, string t) {
    	int ps = 0;
    	int pt = 0;
    	while(ps<s.size() && pt<t.size()){
    		if(s[ps]==t[pt]){
    			ps++;
    		}
    		pt++;
    	}
    	return ps==s.size();
    }
};