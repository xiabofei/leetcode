#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
1) 这个题目纯刷corner cases
2) 处理溢出条件的时候 需要更细致一些 [十位级别溢出 和 个位级别溢出] 分别考虑这两种情况
*/

class Solution {
public:
    int myAtoi(string str) {
    	const int len = str.length();
    	int ret = 0;
    	int i = 0;
    	int sign = 1;
    	while(str[i]==' ' && i<len){i++;}
    	if(i==len) {return 0;}
    	if(str[i]=='+'){i++;}
    	else if(str[i]=='-'){i++; sign=-1;}
    	char curr_c;
    	while(i<len){
    		curr_c = str[i++];
    		if(curr_c<'0' || curr_c>'9'){break;}
    		// 由于前面考虑的符号 这里只需要考虑INT_MAX即可 注意边界条件
    		if(INT_MAX/10 < ret || (INT_MAX/10 == ret && INT_MAX%10 < curr_c-'0')){
    			return sign==1? INT_MAX : INT_MIN;
    		}
    		ret = ret*10 + (curr_c - '0');
    	}
    	return ret * sign;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().myAtoi("2147483648") << endl;
	return 0;
}
