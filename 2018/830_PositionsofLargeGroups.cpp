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
    vector<vector<int>> largeGroupPositions(string S) {
    	vector<vector<int>> ret;
    	int b = 0; 
    	int e = 0;
    	while(e<S.size()){
    		if(S[e]!=S[b]){
    			if(e-b>=3){
    				ret.push_back({b, e-1});
    			}
    			b = e;
    		}
    		e++;
    	}
    	if(e-b>=3){
    		ret.push_back({b, e-1});
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	string S = "abbxxxxzzy";
	Solution().largeGroupPositions(S);
	return 0;
}