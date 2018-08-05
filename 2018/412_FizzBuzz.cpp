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
    vector<string> fizzBuzz(int n) {
    	vector<string> ret(n, "");
    	for(int i=1; i<=n; i++){
    		if(0 == i%3){
    			ret[i-1] += "Fizz";
    		}
    		if(0 == i%5){
    			ret[i-1] += "Buzz";
    		}
    		if(ret[i-1]==""){
    			ret[i-1] = to_string(i);
    		}
    	}
    	return ret;
    }
};