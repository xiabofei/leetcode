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

// https://www.jianshu.com/p/37183b4cbae1
// 硬算 + 不能有循环出现 用hashset记录循环

class Solution {
public:
	int squares_of_digtis(int n){
		int ret = 0;
		while(n>0){
			ret += pow(n%10,2);
			n = n/10;
		}
		return ret;
	}
    bool isHappy(int n) {
    	unordered_set<int> occurred;
    	while(n){
    		n = squares_of_digtis(n);
    		if(n==1){
    			return true;
    		}
    		else if(occurred.find(n)!=occurred.end()){
    			return false;
    		}
    		else{
    			occurred.insert(n);
    		}
    	}
    	return false;
    }
};