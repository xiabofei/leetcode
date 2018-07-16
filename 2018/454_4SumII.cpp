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
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
    	// 暴力解法是O(n四次方) 通过分组 转化为原始的TwoSum问题 用hashmap降低为O(n²)
    	int ret = 0;
    	unordered_map<int, int> val_cnt;
    	// merge A and B
    	for(int i=0; i<A.size(); i++){
    		for(int j=0; j<B.size(); j++){
    			int sum = A[i] + B[j];
    			if(val_cnt.find(sum) != val_cnt.end()){
    				val_cnt[sum]++;
    			}
    			else{
    				val_cnt[sum]=1;
    			}
    		}
    	}
    	// merge C and D
    	for(int i=0; i<C.size(); i++){
    		for(int j=0; j<D.size(); j++){
    			int sum = C[i] + D[j];
    			if(val_cnt.find(0-sum) != val_cnt.end()){
    				ret += val_cnt[0-sum];
    			}
    		}
    	}
    	return ret;
    }
};
