#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution{
	vector<string> letterCombinations(string digits)
	{
		map<char, string> digit_letters;
		digit_letters['2'] = "abc";
		digit_letters['3'] = "def";
		digit_letters['4'] = "ghi";
		digit_letters['5'] = "jkl";
		digit_letters['6'] = "mno";
		digit_letters['7'] = "pqrs";
		digit_letters['8'] = "tuv";
		digit_letters['9'] = "wxyz";
		vector<string> ret;
		if (digits.size()==0) return ret;
		vector<char> tmp;
		Solution::dfs(ret, tmp, digits, digit_letters);
		return ret;
	}
	static void dfs(
		vector<string>& ret, vector<char>& tmp, 
		string digits, map<char, string>& digit_letters)
	{
		if ( tmp.size()==digits.size() )
		{
			ret.push_back(string(tmp.begin(),tmp.end()));
			return;
		}
		int index = tmp.size();
		for ( int i=0; i<digit_letters[digits[index]].size(); ++i )
		{
			tmp.push_back(digit_letters[digits[index]][i]);
			Solution::dfs(ret, tmp, digits, digit_letters);
			tmp.pop_back();
		}
	}
};