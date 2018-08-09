#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://blog.csdn.net/zarlove/article/details/78351332
// O(n)时间复杂度
// 数学问题

class Solution {
public:
    string getPermutation(int n, int k) {
    	string ret;
    	int fact = 1;
    	// 生成一个最小排列 并 计算n!
    	for(int i=1; i<=n; i++){
    		ret += to_string(i);
    		fact *= i;
    	}
    	// 逐个生成
    	int remain = n;
    	int begin = 0;
    	--k;
    	while(remain){
    		fact /= remain;
    		// curr记录的是当前元素的下标
    		int idx = begin + k/fact;
    		// 从begin到curr集体向右rotate一个位置
    		char tmp = ret[idx];
    		for(int i=idx; i>begin; i--){
    			ret[i] = ret[i-1];
    		}
    		ret[begin] = tmp;
    		++begin;
    		--remain;
    		k = k%fact; //已经排除掉k/fact种可能 只剩下k%fact种可能
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().getPermutation(3, 4) << endl;
	return 0;
}