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
    vector<vector<int>> generate(int numRows) {
    	vector<vector<int>> ret;
    	if(numRows<1){return ret;}
    	vector<int> tmp;
    	tmp.push_back(1);
    	ret.push_back(tmp);
    	for(int i=1; i<numRows; i++){
    		for(int j=tmp.size()-1; j>0; j--){
    			tmp[j] += tmp[j-1];
    		}
    		tmp.push_back(1);
    		ret.push_back(tmp);
    	}
    	return ret;
    }
};