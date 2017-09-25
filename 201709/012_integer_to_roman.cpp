#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
这是个从题目的Discuss中学到的解法 感觉比较符合工程化思维 简单高效
1) 学到的技巧就是 num%1000取百位往下 num%100取十位往下
2) 如果是没有进位 则设为空
*/

class Solution {
public:
	string intToRoman(int num) {
		string M[] = {"", "M", "MM", "MMM"};
		string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
	}
};
