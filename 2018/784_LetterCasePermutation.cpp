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
    vector<string> letterCasePermutation(string S) {
    	vector<string> ret;
    	string tmp = S;
    	backtracing(ret, tmp, S, 0);
    	return ret;
    }
    void backtracing(vector<string>& ret, string tmp, string S, int idx){
    	if(idx==S.size()){
    		ret.push_back(tmp);
    		return;
    	}
    	if(S[idx]>='a' && S[idx]<='z'){
    		tmp[idx]= tmp[idx]+'A'-'a';
    		backtracing(ret, tmp, S, idx+1);
    		tmp[idx] = S[idx];
    		backtracing(ret, tmp, S, idx+1);
    	}
    	else if(S[idx]>='A' && S[idx]<='Z'){
    		tmp[idx] = tmp[idx] - 'A' + 'a';
    		backtracing(ret, tmp, S, idx+1);
    		tmp[idx] = S[idx];
    		backtracing(ret, tmp, S, idx+1);
    	}
    	else{
    		backtracing(ret, tmp, S, idx+1);
    	}
    }
};