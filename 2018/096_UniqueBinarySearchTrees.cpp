#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int numTrees(int n) {
    	vector<int> dp(n+1, 0);
    	dp[0] = 1;
    	dp[1] = 1;
    	for(int i=2; i<=n; i++){
    		for(int j=0; j<i; j++){
    			dp[i] += dp[j]*dp[i-j-1];
    		}
    	}
    	return dp[n];
    }
};

// class Solution {
// public:
//     int numTrees(int n) {
//     	map<int, int> numNodes_numTrees;
//     	numNodes_numTrees[0] = 1;
//     	numNodes_numTrees[1] = 1;
//     	numNodes_numTrees[2] = 2;
//     	return Solution::num(n, numNodes_numTrees);
//     }
//     int num(int n, map<int, int>& numNodes_numTrees){
//     	if(n<=1){return 1;}
//     	int ret = 0;
//     	for(int i=0; i<n; i++){
//     		int l = 1;
//     		if(numNodes_numTrees.find(i)!=numNodes_numTrees.end()){
//     			l = numNodes_numTrees[i];
//     		}
//     		else{
//     			l = Solution::numTrees(i);
//     			numNodes_numTrees[i] = l;
//     		}
//     		int r = 1;
//     		if(numNodes_numTrees.find(n-1-i)!=numNodes_numTrees.end()){
//     			r = numNodes_numTrees[n-1-i];
//     		}
//     		else{
//     			r = Solution::numTrees(n-1-i);
//     			numNodes_numTrees[n-1-i] = r;
//     		}
//     		ret += l*r;
//     	}
//     	return ret;
//     }
// };