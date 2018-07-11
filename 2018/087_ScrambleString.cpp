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
    bool isScramble(string s1, string s2) {
    	// 判断s1和s2各个字母数量相等
    	vector<int> alpha(26, 0);
    	for(int i=0; i<s1.size(); i++){
    		alpha[s1[i]-'a']++;
    		alpha[s2[i]-'a']--;
    	}
    	for(int i=0; i<26; i++){
    		if(alpha[i]!=0){return false;}
    	}
    	// 递归返回条件
    	if(s1.size()==1){return s1[0]==s2[0];}
    	// 遍历所有scramble可能(left的长度l)
    	int len = s1.size();
    	for(int l=1; l<len; l++){
    		if(
    			(
    				isScramble(s1.substr(0,l), s2.substr(0,l)) 
    				&& 
    				isScramble(s1.substr(l, len-l), s2.substr(l, len-l))
    			)
    			||
    			(
    				isScramble(s1.substr(0, l), s2.substr(len-l, l))
    				&&
    				isScramble(s1.substr(l, len-l), s2.substr(0, len-l))
    			)
    			){
    			return true;
    		}
    	}
    	return false;
    }
};