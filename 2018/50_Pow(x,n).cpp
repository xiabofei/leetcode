#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

// http://www.cnblogs.com/grandyang/p/4383775.html
// binary search
// pow(x, n) == pow(x, n/2) * pow(x, n/2)

class Solution {
public:
    double myPow(double x, int n) {
    	if(n==0){return 1;}
    	double half = myPow(x, n/2);
    	if(n>0){
    		return n&1 ? half*half*x : half*half; 
    	}
    	else{
    		return n&1 ? half*half/x : half*half;
    	}
    }
};