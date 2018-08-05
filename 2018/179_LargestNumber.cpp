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


// https://blog.csdn.net/feliciafay/article/details/42969511
// 转化成字符串比较
// a1+a2 < a2+a1

class Solution {
public:
	bool static cmp(string s1, string s2){
		return s1+s2 > s2+s1;
	}
    string largestNumber(vector<int>& nums) {
    	vector<string> strs;
    	for(int i=0; i<nums.size(); i++){
    		strs.push_back(to_string(nums[i]));
    	}
    	sort(strs.begin(), strs.end(), cmp);
    	string ret = "";
    	for(int i=0; i<strs.size(); i++){
    		ret += strs[i];
    	}
    	if(ret[0]=='0'){
    		return "0";
    	}
    	return ret;
    }
};
