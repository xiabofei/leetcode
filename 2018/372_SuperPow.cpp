#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 求快速幂
// http://www.cnblogs.com/grandyang/p/5651982.html
// 记住如下两个公式
// a^(10*n+m) = (a^n)^10 * (a^m)
// (a*b)%c = (a%c)*(b%c)

class Solution {
public:
    int superPow(int a, vector<int>& b){
    	long ret = 1;
    	for(int i=0; i<b.size(); i++){
    		ret = my_pow(ret, 10) * my_pow(a, b[i]) % 1337;
    	}
    	return ret;
    }
    int my_pow(int x, int n){
    	if(n==0){return 1;}
    	if(n==1){return x%1337;}
    	return my_pow(x%1337, n/2) * my_pow(x%1337, n-n/2) % 1337;
    }
};
