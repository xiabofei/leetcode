#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
Tips:
有两种方法去解决这道题目
1) int的回文用reverse int的方法去判断
2) 用‘掐头去尾’方法判断
*/

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x<0) return false;
    	int rever = 0;
    	int origin = x;
    	while(x){
    		if(INT_MAX/10 < rever || INT_MIN/10 > rever){
    			return false;
    		}
    		rever = rever*10 + x%10;
    		x = x/10;
    	}
    	return rever == origin;
    }
};

class Solution2 {
public:
    bool isPalindrome(int x) {
    	if(x<0) return false;
    	int d = 1;
    	// 算出位数
    	while(x/10 >= d) {d = d * 10;}
    	int l,r;
    	while(x){
    		r = x%10;
    		l = x/d;
    		if(r!=l){return false;}
    		// 下面两行是 把原来数字掐头去尾 的技巧
    		x = x%d/10;
    		d = d/100;
    	}
    	return true;
    }
};
