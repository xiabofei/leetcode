#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/4385822.html
// 大概思路 先通过办法 把所有str转换成只与字母数量有关的唯一key
// 维护一个hashmap 记录每个key对应的strs

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
    	vector<vector<string>> ret;
    	unordered_map<string, vector<string>> key_strs;
    	for(int i=0; i<strs.size(); i++){
    		string curr = strs[i];
    		sort(curr.begin(), curr.end());
    		key_strs[curr].push_back(strs[i]);
    	}
    	for(auto it: key_strs){
    		ret.push_back(it.second);
    	}
    	return ret;
    }
};