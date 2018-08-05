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


// https://leetcode.com/problems/reverse-words-in-a-string-iii/discuss/102105/C++-Solution
// 注意迭代start和end一起往前迭代 跳过空格

class Solution {
public:
    string reverseWords(string s) {
    	int start = 0;
    	int end = start;
    	while(start<s.size()){
    		while(s[end]!=' ' && end<s.size()){
    			end++;
    		}
    		reverse(s.begin()+start, s.begin()+end);
    		end++;
    		start = end;
    	}
    	return s;
    }
};

int main(int argc, char const *argv[])
{
	string dat = "Let's take LeetCode contest";
	Solution().reverseWords(dat);
	return 0;
}