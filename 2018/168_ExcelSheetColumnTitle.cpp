#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://leetcode.com/problems/excel-sheet-column-title/discuss/51541/Readable-C++-code-within-1ms
// 区别 
// 十进制是0-9
// 二十六进制是1-26 (A-Z)
// 因此 每次先对n-1 再%26 就获得了正确的进位


class Solution {
public:
	string convertToTitle(int n) {
		string ret = "";
		while(n){
			--n;
			ret.push_back(n%26+'A');
			n = n/26;
		}
		reverse(ret.begin(), ret.end());
		return ret;
	}
};