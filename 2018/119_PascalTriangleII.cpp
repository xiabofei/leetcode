#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> ret;
    	ret.push_back(1);
    	for(int i = 1; i <= rowIndex; i++){
    		for(int j=ret.size()-1; j>0; j--){ret[j] += ret[j-1];}
    		ret.push_back(1);
    	}
    	return ret;
    }
};