#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://www.cnblogs.com/rgvb178/p/5974548.html
// 由于只多了一个 还都是ascii码 s加 t减

class Solution {
public:
    char findTheDifference(string s, string t) {
    	if(s.size()<t.size()){swap(s, t);}
    	int sum = 0;
    	for(int i=0; i<t.size(); i++){
    		sum += s[i];
    		sum -= t[i];
    	}
    	sum += s[s.size()-1];
    	return (char)sum;
    }
};
