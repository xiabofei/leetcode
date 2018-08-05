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
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	vector<int> ret;
    	const int len1 = nums1.size(); 
    	const int len2 = nums2.size(); 
    	if(len1==0 || len2==0){return ret;}
    	// 挑短的构造set 保证len1<len2
    	unordered_set<int> unique;
    	if(len1<=len2){
    		for(int i=0; i<len1; i++){
    			unique.insert(nums1[i]);
    		}
    		for(int i=0; i<len2; i++){
    			if(unique.find(nums2[i]) != unique.end()){
    				ret.push_back(nums2[i]);
    				unique.erase(nums2[i]);
    			}
    		}
    		return ret;
    	}
    	else{
    		return intersection(nums2, nums1);
    	}
    }

};
