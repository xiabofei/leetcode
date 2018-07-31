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
    bool isPerfectSquare(int num) {
    	if(num<0){return false;}
    	if(num<=1){return true;}
    	int b = 0;
    	int e = num;
    	while(b<e){
    		int m = b+(e-b)/2;
    		if(num/m > m){
    			b = m+1;
    		}
    		else if(num/m < m){
    			e = m;
    		}
    		else{
    			return m*m==num;
    		}
    	}
    	return false;
    }
};