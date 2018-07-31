#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 画画图--总结通项公式
// range为区间每个数字的digit个数
// range * 9 * pow(10, range-1)

// 采用从小区间到大区间遍历的过程
// 每次尝试减去一个区间的digits 通过这种方法限定range
// 然后再在range区间确定是哪个数字 第几个digit

class Solution {
public:
    int findNthDigit(int n) {
    	int range = 1;
    	while(n>range*9*pow(10, range-1)){
    		n -= range*9*pow(10, range-1);
    		range++;
    	}
    	// 定位到range下的第几个数字
    	int index = (n-1) / range;
    	int digit = (n-1) % range;
    	// 由index和range复原数字
    	int num = pow(10, range-1) +  index;
    	return int(to_string(num)[digit]-'0');
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().findNthDigit(9) << endl;
	return 0;
}