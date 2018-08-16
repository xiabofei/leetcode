#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// http://www.cnblogs.com/grandyang/p/5931874.html
// 跟回文关系不大 主要查奇数偶数
// 先查一遍各个字符的频率
// 如果是偶数个 直接累加到结果中
// 如果是奇数个 减一再累加到结果中
// 长度最大的奇数可以多留一个

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> m;
		for(int i=0; i<s.size(); i++){
			m[s[i]]++;
		}
		int ret = 0;
		bool flag_odd = false;
		for(auto it = m.begin(); it!=m.end(); it++){
			int tmp = it->second;
			ret += tmp;
			if(tmp&1){
				ret--;
				flag_odd = true;
			}
		}
		return flag_odd ? ret + 1 : ret;
	}
};