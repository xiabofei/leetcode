#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 采用归并的思路 时间复杂度保持不变

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.size()==0){return "";}
    	if(strs.size()==1){return strs[0];}
    	return lcp(strs, 0, strs.size()-1);
    }
    string lcp(vector<string>& strs, int b, int e){
    	if(b==e){return strs[b];}
    	int m = (e+b)/2;
    	string lcp_left = lcp(strs, b, m);
    	string lcp_right = lcp(strs, m+1, e);
    	int len = min(lcp_left.size(), lcp_right.size());
    	string curr_lcp = "";
    	for(int i=0; i<len; i++){
    		if(lcp_left[i]!=lcp_right[i]){
    			break;
    		}
    		curr_lcp += lcp_left[i];
    	}
    	return curr_lcp;
    }
};
