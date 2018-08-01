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

// dp过程迭代n本身
// dp[i]表示sum==i时 最少需要多少个平方数的和

class Solution {
public:
    int numSquares(int n) {
    	vector<int> dp(n+1, 0);
    	// 对dp初始化 最次每个sum可以用i个1构成
    	for(int i=1; i<=n; i++){
    		dp[i] = i;
    	}
    	for(int i=2; i<=n; i++){
    		// 在i固定的情况下 遍历所有平方小于i的数
    		for(int j=1; j*j<=i; j++){
    			dp[i] = min(dp[i], dp[i-j*j]+1);
    		}
    	}
    	return dp[n];
    }
};

int main(int argc, char const *argv[])
{
	cout << Solution().numSquares(12) << endl;
	return 0;
}