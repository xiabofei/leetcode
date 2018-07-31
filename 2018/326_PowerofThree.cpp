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
    bool isPowerOfThree(int n) {
    	int largest = pow(3, 19);
    	return (n > 0) && (largest%n ==0); 
    }
};