#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

// 有个基础版本[392. Is Subsequence] https://leetcode.com/problems/is-subsequence/description/
// 是否是子串 two pointers 不断匹配短的 双双往前推进


// https://leetcode.com/problems/number-of-matching-subsequences/discuss/117575/C++-12-Line-Solution-with-Explanation
// 作为Is Subsequence的加强版 
// 用额外的二维数组 记录每个字母依次出现的位置

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
    	vector<vector<int>> alpha(26, vector<int>());
    	// 记录S中每个字母依次出现的位置
    	for(int i=0; i<S.size(); i++){alpha[S[i]-'a'].push_back(i);}
    	// 逐个验证word
    	int ret = 0;
    	for(int i=0; i<words.size(); i++){
    		string curr = words[i];
    		// 迭代idx为curr单词的当前字符下标
    		int idx = -1;
    		bool flag = true;
    		for(int j=0; j<curr.size(); j++){
    			char c = curr[j];
    			// 当前字母的出现位置是否满足比上一个字母的idx大
    			flag = false;
    			if(alpha[c-'a'].empty()){
    				continue;
    			}
    			for(int k=0; k<alpha[c-'a'].size(); k++){
    				if(alpha[c-'a'][k]>idx){
    					idx = alpha[c-'a'][k];
    					flag = true;
    					break;
    				}
    			}
    			if(!flag){
    				break;
    			}
    		}
    		if(flag){
    			ret++;
    		}
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	string dat = "abcde";
	vector<string> words = {"a", "bb", "acd", "ace"};
	cout << Solution().numMatchingSubseq(dat, words) << endl;
	return 0;
}
