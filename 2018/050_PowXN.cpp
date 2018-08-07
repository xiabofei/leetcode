#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 这种pow(x, n)的问题 先往二分和归并上靠
// 时间复杂度是log(n)
// 尽量缩减x*x的次数
// 常规思路
// 		pow(x, 4) = pow(x, 2) × pow(x, 2)
// 巧妙递归思路
// 		pow(x, 4) = pow(x*x, 2)
// 		pow(x, 5) = pow(x*x, 5/2) * x

class Solution {
public:
    double myPow(double x, int n) {
    	// 返回条件
    	if(n==0){return 1;}
    	// n小于零在最开始就处理了
    	if(n<0){
    		n = -n;
    		x = 1/x;
    	}
    	return n&1 ? x * myPow(x*x, n/2) : myPow(x*x, n/2);
    }
};
