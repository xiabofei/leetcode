#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if(num<=0){return false;}
    	if(num==1){return true;}
    	vector<int> divider = {30, 15, 10, 6, 5, 3, 2};
    	while(num>0){
    		int last = num;
    		for(int i=0; i<divider.size(); i++){
    			if(last%divider[i]==0){
    				last = last / divider[i];
    				break;
    			}
    		}
    		if(last==num){
    			return false;
    		}
    		num = last;
    		if(num==1){
    			return true;
    		}
    	}
    	return num==1;
    }
};