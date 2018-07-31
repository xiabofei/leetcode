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
	vector<int> hours = {1, 2, 4, 8};
	vector<int> minutes = {1, 2, 4, 8, 16, 32};
    vector<string> readBinaryWatch(int num) {
    	vector<string> ret;
    	// hour最多3个灯
    	// minutes5个灯
    	if(num>8){return ret;}
    	for(int h=0; h<=min(num, 3); h++){
    		int m = num-h;
    		if(m>5){continue;}
    		// hour用h个灯
    		vector<string> h_opts;
    		vector<int> tmp;
    		backtracing(true, h_opts, tmp, hours, 0, h);
    		// minute用m个灯
    		vector<string> m_opts;
    		tmp.clear();
    		backtracing(false, m_opts, tmp, minutes, 0, m);
    		// 二者交叉
    		for(int i=0; i<h_opts.size(); i++){
    			for(int j=0; j<m_opts.size(); j++){
    				ret.push_back(h_opts[i]+":"+m_opts[j]);
    			}
    		}
    	}
    	return ret;
    }
    void backtracing(
    	bool hour,
    	vector<string>& ret, vector<int> tmp, vector<int>& candidates, 
    	const int pos, const int limits){
    	if(tmp.size()==limits){
    		int sum = 0;
    		for(int i=0; i<tmp.size(); i++){sum += tmp[i];}
    		if(!hour){
    			if(sum<10){
    				ret.push_back("0"+to_string(sum));
    			}
    			else if(sum<60){
    				ret.push_back(to_string(sum));
    			}
    		}
    		else{
    			if(sum<12){
    				ret.push_back(to_string(sum));
    			}
    		}
    		return;
    	}
    	for(int i=pos; i<candidates.size(); i++){
    		tmp.push_back(candidates[i]);
    		backtracing(hour, ret, tmp, candidates, i+1, limits);
    		tmp.pop_back();
    	}
    }
};

