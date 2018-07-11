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
    vector<vector<int>> transpose(vector<vector<int>>& A) {
    	vector<vector<int>> dump;
    	if(A.size()==0){return dump;}
    	const int row_num = A.size();
    	const int col_num = A[0].size();
    	vector<vector<int>> ret(col_num, vector<int>(row_num, 0));
    	if(A.size()==0){return ret;}
    	for(size_t i=0; i<row_num; i++){
    		for(size_t j=0; j<col_num; j++){
    			ret[j][i] = A[i][j];
    		}
    	}
    	return ret;
    }
};