#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 判断数字回文的套路
// 	ret = ret*10 + x%10
// 	x = x/10;

class Solution {
public:
    bool isPalindrome(int x) {
    	if(x<0){return false;}
    	int target = x;
    	long ret = 0;
    	while(x){
    		ret = ret*10 + x%10;
    		x = x/10;
    	}
    	return target==ret;
    }
};
