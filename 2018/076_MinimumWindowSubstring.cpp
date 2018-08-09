#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// http://www.cnblogs.com/grandyang/p/4340948.html
// 用hashmap记录每个字母的个数
// 用two point一前一后 滑动窗口
// left right一旦满足t中的需求 则更新一次最小的 
// 滑动策略 如果s[right]不在t中 就跳过

class Solution {
public:
	string minWindow(string s, string t) {
		if(t.size()>s.size()){return "";}
		if(t.size()==0){return "";}
		unordered_map<char, int> alpha_cnt;
    	// 记录target字符串中各个字符的count
		for(int i=0; i<t.size(); i++){
			if(alpha_cnt.find(t[i])!=alpha_cnt.end()){
				alpha_cnt[t[i]]++;
			}
			else{
				alpha_cnt[t[i]] = 1;
			}
		}
		int min_len = INT_MAX;
		string ret = "";
		int l = 0;
		int r = 0;
		int match_cnt = 0;
		while(r<s.size()){
			if(alpha_cnt.find(s[r]) != alpha_cnt.end()){
				--alpha_cnt[s[r]];
				if(alpha_cnt[s[r]]>=0){
					++match_cnt;
				}
				while(match_cnt==t.size()){
					if(min_len>r-l+1){
						cout << l << endl;
						min_len = r-l+1;
						ret = s.substr(l, r-l+1);
					}
					if(alpha_cnt.find(s[l]) != alpha_cnt.end()){
						++alpha_cnt[s[l]];
						if(alpha_cnt[s[l]]>0){
							--match_cnt;
						}
					}
					++l;
				}
			}
			r++;
		}
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	Solution().minWindow("ADOBECODEBANC", "ABC");
	return 0;
}