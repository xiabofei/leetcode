#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// divide and conquer
// 怎么找分割点 : total频率小于k的都都可以作为分割点

class Solution {
public:
    int longestSubstring(string s, int k) {
    	if(s.size()<k){return 0;}
    	// 统计每个字符的频率
    	vector<int> m(26, 0);
    	for(int i=0; i<s.size(); i++){
    		m[s[i] - 'a'] += 1;
    	}
    	// 找分割点
    	int split = 0;
    	while(split<s.size() && m[s[split]-'a']>=k){split++;}
    	if(split==s.size()){
    		// 全部满足条件
    		return s.size();
    	}
    	// divde
    	int left = longestSubstring(s.substr(0, split), k);
    	int right = longestSubstring(s.substr(split+1), k);
    	return max(left, right);
    }
};