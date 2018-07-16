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
	void quick_sort(vector<int>& nums, int b, int e){
		if(b>=e){return;}
		int l = b;
		int r = e;
		while(l<r){
			while(l<r && nums[r]>=nums[b]){r--;}
			while(l<r && nums[l]<=nums[b]){l++;}
			swap(nums[l], nums[r]);
		}
		swap(nums[b], nums[r]);
		quick_sort(nums, b, r-1);
		quick_sort(nums, r+1, e);
	}
	void adjust_heap(vector<int>& nums, int b, int e){
		while(b<=e/2-1){
			int child = 2*b+1;
			if(child+1<e && nums[child]>nums[child+1]){
				child += 1;
			}
			if(nums[b]<=nums[child]){break;}
			swap(nums[b], nums[child]);
			b = child;
		}
	}
	void heap_sort(vector<int>& nums){
		for(int i=(nums.size()-1)/2; i>=0; i--){
			adjust_heap(nums, i, nums.size());
		}
		for(int l=nums.size(); l>0; l--){
			swap(nums[0], nums[l-1]);
			adjust_heap(nums, 0, l-1);
		}
	}
    bool containsDuplicate(vector<int>& nums) {
    	if(nums.size()<2){return false;}
    	// sort(nums.begin(), nums.end());
    	// quick_sort(nums, 0, nums.size()-1);
    	heap_sort(nums);
    	for(int i=1; i<nums.size(); i++){
    		if(nums[i]==nums[i-1]){
    			return true;
    		}
    	}
    	return false;
    	/*
    	if(nums.size()<2){return false;}
    	unordered_set<int> vals;
    	for(int i=0; i<nums.size(); i++){
    		if(vals.find(nums[i])!=vals.end()){
    			return true;
    		}
    		else{
    			vals.insert(nums[i]);
    		}
    	}
    	return false;
    	*/
    }
};