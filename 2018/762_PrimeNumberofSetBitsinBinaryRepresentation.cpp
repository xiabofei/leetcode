#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/discuss/113227/JavaC++-Clean-Code
// 统计int中bit1的个数

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
    	unordered_set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
    	int ret = 0;
    	for(int i=L; i<=R; i++){
    		int curr = 0;
    		// 统计int中bit1的个数
    		for(int n=i; n; n &= (n-1)){
    			++curr;
    		}
    		ret += (primes.find(curr)!=primes.end()? 1 : 0);
    	}
    	return ret;
    }
};