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


// https://leetcode.com/problems/reverse-string-ii/discuss/100887/C++Java-Clean-Code
// 学习一下clean code的写法

class Solution {
public:
    string reverseStr(string s, int k) {
    	for(int start = 0; start<s.size(); start += k*2){
    		for(int l=start, r=min(start+k-1, (int)s.size()-1); l<r; l++, r--){
    			swap(s[l], s[r]);
    		}
    	}
    	return s;
    }
};
