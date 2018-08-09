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
    int lengthOfLastWord(string s) {
    	int ret = 0;
    	int i=s.size()-1;
    	while(s[i]==' '){i--;}
    	while(i>=0){
    		if(s[i]!=' '){
    			ret++;
    		}
    		else{
    			break;
    		}
    		i--;
    	}
    	return ret;
    }
};