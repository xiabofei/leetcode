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
    vector<int> majorityElement(vector<int>& nums) {
    	vector<int> ret;
    	// Moore Voting投票法找出两个众数
    	int cand1 = 0;
    	int cnt1 = 0;
    	int cand2 = 0;
    	int cnt2 = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]==cand1){
    			cnt1++;
    		}
    		else if(nums[i]==cand2){
    			cnt2++;
    		}
    		else if(cnt1==0){
    			cand1 = nums[i];
    			cnt1 = 1;
    		}
    		else if(cnt2==0){
    			cand2 = nums[i];
    			cnt2 = 1;
    		}
    		else{
    			// 出现一个不同的 cnt1和cnt2都减少
    			cnt1--;
    			cnt2--;
    		}
    	}
    	// 验证是否是符合条件的众数
    	cnt1 = 0;
    	cnt2 = 0;
    	for(int i=0; i<nums.size(); i++){
    		if(nums[i]==cand1){
    			cnt1++;
    		}
    		else if(nums[i]==cand2){
    			cnt2++;
    		}
    	}
    	if(cnt1>nums.size()/3){
    		ret.push_back(cand1);
    	}
    	if(cnt2>nums.size()/3 && cand2!=cand1){
    		ret.push_back(cand2);
    	}
    	return ret;
    }
};
int main(int argc, char const *argv[])
{
	cout << '1' << endl;
	vector<int> data{2,2};
	Solution().majorityElement(data);
	return 0;
}