#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// http://www.cnblogs.com/grandyang/p/5631814.html
// 在bit上做加法操作
// 二进制每个位置上的digit a^b
// 二进制每个位置上的进位digit (a&b)<<1

class Solution {
public:
    int getSum(int a, int b) {
    	if(b==0){return a;}
    	if(a==0){return b;}
    	int bit_sum = a ^ b;
    	int bit_carry = (a&b)<<1;
    	return getSum(bit_sum, bit_carry);
    }
};