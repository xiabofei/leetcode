#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// bianry的问题 能用bit运算就不用乘法除法


class Solution {
public:
    string addBinary(string a, string b) {
    	if(a.size()==0){return b;}
    	if(b.size()==0){return a;}
    	const int len_a = a.size();
    	const int len_b = b.size();
    	string ret;
    	int ia = len_a-1;
    	int ib = len_b-1;
    	int curr = 0;
    	int carry = 0;
    	while(ia>=0 && ib>=0){
    		curr = (a[ia]-'0') ^ (b[ib]-'0') ^ carry;
    		carry = (((a[ia]-'0') + (b[ib]-'0') + carry)>=2 ? 1 : 0);
    		ret.push_back(curr+'0');
    		ia--;
    		ib--;
    	}
    	while(ia>=0){
    		curr = (a[ia]-'0') ^ carry;
    		carry = (a[ia]-'0') & carry;
    		ret.push_back(curr+'0');
    		ia--;
    	}
    	while(ib>=0){
    		curr = (b[ib]-'0') ^ carry;
    		carry = (b[ib]-'0') & carry;
    		ret.push_back(curr+'0');
    		ib--;
    	}
    	if(carry){
    		ret.push_back('1');
    	}
    	reverse(ret.begin(), ret.end());
    	return ret;
    }
};
