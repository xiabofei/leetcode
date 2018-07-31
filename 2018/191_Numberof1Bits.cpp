#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
    	int ret = 0;
    	for(int i=0; i<32; i++){
    		ret += n&1;
    		n = n>>1;
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().hammingWeight(3) << endl;;
	return 0;
}