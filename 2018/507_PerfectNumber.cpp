#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// http://www.cnblogs.com/grandyang/p/6636879.html
// 1) num%i==0 则i和num/i都应该累加
// 2) [2, sqrt(num)]是范围
// 3) 必须累加完 退出循环再判断

class Solution {
public:
    bool checkPerfectNumber(int num) {
    	if(num==1){return false;}
    	int sum = 1;
    	for(int i=2; i*i<=num; i++){
    		// 每次找到能整除的 把i和num/i都加上
    		if(num%i==0){sum += (i+num/i);}
    		// 如果遇到4/2==2这种情况 只能加一个2
    		if(i*i==num){sum -= i;}
    		// 如果sum已经超过num了 则直接false
    		if(sum>num){return false;}
    	}
    	// 退出循环后再判断一次 因为可能sum<num
    	return sum==num;
    }
};