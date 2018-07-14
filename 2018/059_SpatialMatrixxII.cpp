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
        int r1 = 0;
        int r2 = n-1;
        int c1 = 0;
        int c2 = n-1;
        int val = 0;
        while(r1<=r2 && c1<=c2){
            // up row
            for(int i=c1; i<=c2; i++){
                ret[r1][i] = ++val;
            }
            // left column
            for(int i=r1+1; i<=r2; i++){
                ret[i][c2] = ++val;
            }
            // bottom row
            if(r1!=r2){
                for(int i=c2-1; i>=c1; i--){
                    ret[r2][i] = ++ val;
                }
            }
            // right column
            if(c1!=c2){
                for(int i=r2-1; i>=r1+1; i--){
                    ret[i][c1] = ++val;
                }
            }
            r1++;
            r2--;
            c1++;
            c2--;
        }
        return ret;
    }
};