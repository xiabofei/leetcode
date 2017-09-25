#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
1) 0 和 numRows-1 的两个位置的 直接增加 numRows*2-2 直到超出字符串长度
2) 中间位置的 需要一次处理两个起始位置 index1 和 numRows*2-2-index1
*/

class Solution {
public:
	string convert(string s, int numRows) {
		if(numRows<2){return s;}
		const size_t len = s.length();
		vector<char> ret;
		size_t j, index1, index2;
		const size_t gap = numRows*2 - 2;
		for(size_t i = 0; i < numRows; i++){
			index1 = i;
			j = 0;
			if(i==0 || i==numRows-1)
			{
				while(index1+j*gap<len){
					ret.push_back(s[index1 + j*gap]);
					j++;
				}
			}
			else{
				index2 = gap - index1;
				while(index1+j*gap<len){
					ret.push_back(s[index1 + j*gap]);
					if(index2+j*gap<len){
						ret.push_back(s[index2 + j*gap]);
					}
					j++;
				}
			}
		}
		return string(ret.begin(), ret.end());
	}
};

int main(int argc, char const *argv[])
{
	cout << Solution().convert("ABCDE", 4) << endl;
	return 0;
}