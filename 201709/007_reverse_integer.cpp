#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	int ret = 0;
    	while(x){
    		// 溢出条件判断 
    		if(INT_MAX/10 < ret || INT_MIN/10 > ret){
    			return 0;
    		}
    		// reverse整数的逻辑 
    		ret = ret*10 + x%10;
    		x = x/10;
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().reverse(123) << endl;
	return 0;
}
