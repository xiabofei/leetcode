#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// http://www.cnblogs.com/grandyang/p/4521224.html
// 用双hashmap的思路
// 1) 一个hashmap 存放words中所有的word的个数
// 2) 一个hashmap 存放以当前位置开始所有word的个数


class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
    	vector<int> ret;
    	if(s.empty() || words.empty()){return ret;}
    	const int nums = words.size();
    	const int len = words[0].size();
    	// 用hashmap存放words中所有的word个数
    	unordered_map<string, int> word_cnt;
    	for(int i=0; i<words.size(); i++){
    		++word_cnt[words[i]];
    	}
    	// 用hashmap存放以b开始的len*nums个子串中各个words的数量
    	unordered_map<string, int> tmp_word_cnt;
    	// 直接用s.size()的时候要注意 因为s.size()-len*nums有可能是小于0 
    	// 但是受限于s.size()的类型 最小就0 容易出现问题
    	for(int b=0; b<=(int)s.size()-len*nums; b++){
    		tmp_word_cnt.clear();
    		// 每次往前走一个单词的长度 一共走nums个单词
    		int k=0;
    		while(k<nums){
    			string word = s.substr(b+k*len, len);
    			if(word_cnt.find(word)==word_cnt.end()){break;}
    			tmp_word_cnt[word]++;
    			if(tmp_word_cnt[word]>word_cnt[word]){break;}
    			k++;
    		}
    		// 所有的单词都走完了 且数目一致 则加入b
    		if(k==nums){ret.push_back(b);}
    	}
    	return ret;
    }
};