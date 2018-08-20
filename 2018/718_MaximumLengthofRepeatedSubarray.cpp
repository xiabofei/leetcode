#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 最长连续子串的变种

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
    	if(A.size()==0 || B.size()==0){return 0;}
    	const int len_a  = A.size();
    	const int len_b = B.size();
    	int ret = 0;
    	// dp[a][b] 为A[0:a]与B[:b]的最长重复子数组(这里的子数组必须的是连续的)
    	// 并完成dp初始化
    	vector<vector<int>> dp(len_a+1, vector<int>(len_b+1, 0));
    	// 走dp
    	for(int a = 1; a <= len_a; a++){
    		for(int b = 1; b <= len_b; b++){
    			dp[a][b] = A[a-1]==B[b-1] ? dp[a-1][b-1]+1 : 0;
    			ret = max(ret, dp[a][b]);
    		}
    	}
    	return ret;
    }
};