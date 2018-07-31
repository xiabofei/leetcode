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
    vector<int> findAnagrams(string s, string p) {
    	vector<int> ret;
    	const int len_s = s.size();
    	const int len_p = p.size();
    	if(len_s<len_p){return ret;}
    	// 统计p中各个字母的出现次数
    	vector<int> alpha_p(26, 0);
    	for(int i=0; i<len_p; i++){alpha_p[p[i]-'a']++;}
    	// 记录s中各个字母的出现次数
    	vector<int> alpha_s(26, 0);
    	for(int i=0; i<len_p; i++){alpha_s[s[i]-'a']++;}
    	if(comp(alpha_s, alpha_p)){ret.push_back(0);}
    	// 迭代后面的位置
    	for(int i=1; i<=len_s-len_p; i++){
    		alpha_s[s[i-1]-'a']--;
    		alpha_s[s[i+len_p-1]-'a']++;
    		if(comp(alpha_s, alpha_p)){
    			ret.push_back(i);
    		}
    	}
    	return ret;
    }
    bool comp(vector<int>& alpha_s, vector<int>& alpha_p){
    	for(int i=0; i<26; i++){
    		if(alpha_s[i]!=alpha_p[i]){
    			return false;
    		}
    	}
    	return true;
    }
};