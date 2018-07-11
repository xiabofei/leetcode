#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
    	vector<int> ret;
    	int pos = search(nums, 0, nums.size()-1, target);
    	if(pos==-1){
    		ret.push_back(-1);
    		ret.push_back(-1);
    	}
    	else{
    		int tmp = pos;
    		// left
    		int l = pos;
    		int b = 0;
    		while(b<=l){
    			int m = (b+l)/2;
    			if(nums[m]==target){
    				tmp = m;
    				l = m-1;
    			}
    			else{
    				b = m+1;
    			}
    		}
    		ret.push_back(tmp);
    		tmp = pos;
    		// right
    		int r = pos;
    		int e = nums.size()-1;
    		while(r<=e){
    			int m = (r+e)/2;
    			if(nums[m]==target){
    				tmp = m; 
    				r = m+1;
    			}
    			else{
    				e = m-1;
    			}
    		}
    		ret.push_back(tmp);
    	}
    	return ret;

    }
    int search(vector<int>& nums, int b, int e, int target){
    	if(b>e){return -1;}
    	if(b==e){return nums[b]==target ? b : -1;}
    	int m = (b+e)/2;
    	if(nums[m]==target){
    		return m;
    	}
    	else if(nums[m]<target){
    		return search(nums, m+1, e, target);
    	}
    	else{
    		return search(nums, b, m-1, target);
    	}
    }
};

int main(int argc, char const *argv[])
{
	vector<int> arr;
	arr.push_back(1);
	Solution().searchRange(arr, 1);
	return 0;
}