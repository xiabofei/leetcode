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


class Solution {
public:
    int titleToNumber(string s) {
    	int ret = 0;
    	for(int i=0; i<s.size(); i++){
    		int curr = s[i] - 'A' + 1;
    		ret = 26*ret + curr;
    	}
    	return ret;
    }
};