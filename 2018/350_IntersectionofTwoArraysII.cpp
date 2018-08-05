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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    	unordered_map<int, int> num_cnt;
    	vector<int> ret;
    	for(int i=0; i<nums1.size(); i++){
    		num_cnt[nums1[i]]++;
    	}
    	for(int i=0; i<nums2.size(); i++){
    		if(num_cnt.find(nums2[i])!=num_cnt.end() && --num_cnt[nums2[i]]>=0){
    			ret.push_back(nums2[i]);
    		}
    	}
    	return ret;
    }
};