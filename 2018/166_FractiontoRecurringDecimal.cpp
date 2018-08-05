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

// https://leetcode.com/problems/fraction-to-recurring-decimal/discuss/51160/0ms-C++-Solution-with-Detailed-Explanations
// 核心是小数部分重复数字的问题 结论是一旦出现重复就会一直重复下去
// 考虑正负 区分整数部分和小数部分
// 小数部分用维护一个hashmap 记录是否有相同的[余数]出现
// 迭代小数部分有个公式技巧 : 
//  remain = (remain % denominator) * 10
// 注意remain等都用long操作

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
    	// 分子为0
    	if(numerator==0){return "0";}
    	string ret;
    	// 处理正负的问题
    	if((numerator<0) ^ (denominator<0)){
    		ret += "-";
    	}
    	// 分子分母绝对值化(考虑边界值)
    	long num = numerator>0 ? (long)numerator : (long)numerator*(-1);
    	long den = denominator>0 ? (long)denominator : (long)denominator*(-1);
    	// 整数部分
    	long intergral = num/den; 
    	ret += to_string(intergral);
    	// 小数部分
    	long remain = num%den;
    	if(0==remain){return ret;}
    	ret += ".";
    	// 迭代小数部分 看看是否有相同的余数出现
    	remain *= 10;
    	unordered_map<long, long> rmn_pos;
    	while(remain){
    		long digit = remain / den;
    		if(rmn_pos.find(remain) != rmn_pos.end()){
    			ret.insert(rmn_pos[remain], 1, '(');
    			ret += ")";
    			break;
    		}
    		rmn_pos[remain] = ret.size();
    		ret += to_string(digit);
    		remain = (remain % den ) * 10;
    	}
    	return ret;
    }
};
