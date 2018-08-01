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
    int mySqrt(int x){
    	if(x<=1){return x;}
    	int b = 0;
    	int e = x;
    	while(b<e){
    		int mid = b+(e-b)/2;
    		if(x/mid>mid){
    			b = mid+1;
    		}
    		else if(x/mid<mid){
    			e = mid;
    		}
    		else{
    			return mid;
    		}
    	}
    	return e-1;
    }
};
