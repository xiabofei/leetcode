#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 用hash map存letter to word的关系
// 用hash map存word to string关系
// 分几种情况讨论:
// 1) 如果在两个hash map中都不存在 更新两个hashmap
// 2) 如果在两个hash map中都存在 则看是否相等
// 3) 如果一个存在 另一个不存在 则false

class Solution {
public:
    bool wordPattern(string pattern, string str) {
    	unordered_map<char, string> m_cs;
    	unordered_map<string, char> m_sc;
    	vector<string> words;
    	int b = 0;
    	for(int i=0; i<str.size(); i++){
    		if(str[i]==' '){
    			words.push_back(str.substr(b, i-b));
    			b = i+1;
    		}
    	}
    	words.push_back(str.substr(b, str.size()-b));
    	if(pattern.size()!=words.size()){return false;}
    	for(int i=0; i<pattern.size(); i++){
    		if(m_cs.find(pattern[i])==m_cs.end() && m_sc.find(words[i])==m_sc.end()){
    			m_cs[pattern[i]] = words[i];
    			m_sc[words[i]] = pattern[i];
    		}
    		else if(m_cs.find(pattern[i])!=m_cs.end() && m_sc.find(words[i])!=m_sc.end()){
    			if(m_cs[pattern[i]]!=words[i]){
    				return false;
    			}
    		}
    		else{
    			return false;
    		}
    	}
    	return true;
    }
};