
#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
1) substring用dp存中间结果 牺牲空间复杂度
2) 分类讨论回文长短
*/

class Solution {
public:
	string longestPalindrome(string s) {
		const size_t len = s.length();
		if(len==0){return s;}
		bool dp[len][len];
		std::fill_n(&dp[0][0], len*len,	false);
		size_t start = 0;
		size_t end = 0;
		for(size_t i = 0; i<len; i++){ dp[i][i]=true;}
		for(size_t r = 0; r<len; r++){
			for(size_t l = 0; l<r; l++){
				if(r-l<2){
					dp[l][r] = s[r] == s[l]; 
				}
				else{
					dp[l][r] = dp[l+1][r-1] && s[l]==s[r];
				}
				if(dp[l][r] && r-l > end-start){
					start = l;
					end = r;
				}
			}
		}
		return s.substr(start, end-start+1);
	}
};


int main(int argc, char const *argv[])
{
	// string s = "babad";
	string s = "";
	cout << Solution().longestPalindrome(s) << endl;
	return 0;
}