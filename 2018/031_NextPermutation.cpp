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
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1){return;}
        int idx = nums.size()-1;
        // right to left : 找到第一个right比left大的位置记为idx
        while(idx>0){
            if(nums[idx]>nums[idx-1]){
                break;
            }
            idx--;
        }
        // 全逆序
        if(idx==0){
            reverse(nums.begin(), nums.end());
            return;
        }
        // right to left : 找到第一个比idx-1大的位置
        int pos = nums.size()-1;
        while(nums[pos]<=nums[idx-1]){
            pos--;
        }
        swap(nums[idx-1], nums[pos]);
        reverse(nums.begin()+idx, nums.end());
    }
};