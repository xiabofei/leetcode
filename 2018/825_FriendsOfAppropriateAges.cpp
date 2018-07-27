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
    int numFriendRequests(vector<int>& ages) {
    	if(ages.size()==0){return 0;}
    	if(ages.size()==1){return 1;}
    	// 利用缓存 维护每个年龄的reqs值
    	unordered_map<int, int> age_reqs;
    	// 生成age由大到小的序列
    	sort(ages.begin(), ages.end());
    	reverse(ages.begin(), ages.end());
    	int ret = 0;
    	for(int i=0; i<ages.size(); i++){
    		if(age_reqs.find(ages[i])!=age_reqs.end()){
    			ret += age_reqs[ages[i]];
    		}
    		else{
    			int sum = 0;
    			for(int j=i+1; j<ages.size(); j++){
    				if(valid(ages[i], ages[j])){
    					sum++;
    				}
    			}
    			ret += sum;
    			age_reqs[ages[i]] = sum;
    		}
    	}
    	return ret;
    }
    bool valid(int A, int B){
    	if(B <= (0.5*A+7)){
    		return false;
    	}
    	if(B > 100 && A < 100){
    		return false;
    	}
    	return true;
    }
};
