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
    int firstUniqChar(string s) {
    	// 记录首字母的位置
    	vector<int> alpha(26, -1);
    	// 字母 和 首次位置
    	unordered_map<char, int> m;
    	for(int i=0; i<s.size(); i++){
    		if(-1==alpha[s[i]-'a']){
    			alpha[s[i]-'a'] = i;
    		}
    		m[s[i]]++;
    	}
    	// 最小unique字母位置
    	int ret = INT_MAX;
    	for(auto it: m){
    		if(it.second==1){
    			ret = min(ret, alpha[it.first-'a']);
    		}
    	}
    	if(INT_MAX==ret){
    		return -1;
    	}
    	return ret;
    }
};