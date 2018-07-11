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
    vector<vector<int>> generateMatrix(int n) {
    	vector<vector<int>> ret(n, vector<int>(n, 0));
    	int k = 1;
    	int loop = 0;
    	while(k<=n*n){
    		int p = loop;
    		// left to right : 行坐标都是loop 列坐标递进范围
    		while(p<n-loop){
    			ret[loop][p++] = k++;
    		}
    		// up to down : 行坐标递减 列坐标都是n-loop-1
    		p = loop+1;
    		while(p<n-loop){
    			ret[p++][n-loop-1] = k++;
    		}
    		// right to left : 行坐标不变都是n-loop-1 列坐标递减
    		p = n - 2 - loop;
    		while(p>=loop){
    			ret[n-loop-1][p--] = k++;
    		}
    		// down to up : 行坐标递减 列坐标不变 都是loop
    		p = n - 2 - loop;
    		while(p>loop){
    			ret[p--][loop] = k++;
    		}
    		loop++;
    	}
    	return ret;
    }
};