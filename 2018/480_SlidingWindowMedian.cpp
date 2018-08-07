#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <multiset>

using namespace std;


// 还是大小堆的解决方案 
// 每次多了一个remove操作 时间复杂度是log(k)
// multiset 插入/查找/删除 均是log(k)复杂度 基于红黑树实现


class Solution {
public:
	vector<double> medianSlidingWindow(vector<int>& nums, int k) {
		vector<double> ret;
		multiset<int> small;
		multiset<int> large;
		for(int i=0; i<k; i++){
			add_num(small, large, nums[i]);
		}
		ret.push_back(get_median(small, large, k));
		for(int i=k; i<nums.size(); i++){
			del_num(small, large, nums[i-k]);
			add_num(small, large, nums[i]);
			ret.push_back(get_median(small, large, k));
		}
		return ret;
	}
	double get_median(multiset<int>& small, multiset<int>& large, const int k){
		if(k&1){
			return *small.rbegin();
		}
		else{
			return (*small.rbegin()*0.5)+(*large.begin()*0.5);
		}
	}
	void del_num(multiset<int>& small, multiset<int>& large, const int num){
		if(small.count(num)>0){
			small.erase(small.find(num));
		}
		else{
			large.erase(large.find(num));
		}
	}
	void add_num(multiset<int>& small, multiset<int>& large, const int num){
		if(small.size()<=large.size()){
			if(large.empty() || num<=*large.begin()){
				small.insert(num);
			}
			else{
				small.insert(*large.begin());
				large.erase(large.begin());
				large.insert(num);
			}
		}
		else{
			if(num>*small.rbegin()){
				large.insert(num);
			}
			else{
				large.insert(*small.rbegin());
				small.erase(--small.end());
				small.insert(num);
			}
		}
	}
};