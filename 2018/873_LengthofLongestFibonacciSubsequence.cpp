#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 斐波那契数列中只要挑出两个相邻的数 就能确定整个数组
// https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/discuss/152537/C++-DP-solution

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& A){
    	unordered_map<int, int> val_idx;
    	// 严格递增 统计每个val的位置 空间换时间
    	const int N = A.size();
    	for(int i=0; i<N; i++){
    		val_idx[A[i]] = i;
    	}
    	// dp[l][r] 以A[l]和A[r]结尾的斐波那契序列长度 其中l<r
    	int ret = 0;
    	vector<vector<int>> dp(N, vector<int>(N, 2));
    	for(int r=1; r<N; r++){
    		for(int l=r-1; l>=0; l--){
    			int val = A[r]-A[l];
    			// 存在包含A[l]和A[r]的数组 且 坐标小于l
    			if(val_idx.find(val)!=val_idx.end() && val_idx[val]<l){
    				dp[l][r] = dp[val_idx[val]][l]+1;
    				ret = max(ret, dp[l][r]);
    			}
    		}
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	vector<int> dat = {1,2,3,4,5,6,7,8};
	Solution().lenLongestFibSubseq(dat);
	return 0;
}