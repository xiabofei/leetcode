#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <numeric>

using namespace std;
/*
把每一轮的结果保存下来到中间的数组中
*/

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		if(digits=="") return ret;
		string dict[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		ret.push_back("");
		for(int i=0; i<digits.size(); i++){
			string candidate = dict[digits[i]-'0'];
			vector<string> tmp;
			for(int k=0; k < candidate.size(); k++){
				for(int j=0; j<ret.size(); j++){
					tmp.push_back(ret[j]+candidate[k]);
				}
			}
			ret = tmp;
		}
		return ret;
	}
};
