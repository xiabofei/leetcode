#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

// 比较直观的是接近O(n²)时间复杂度的算法 可以先说一种实现方法 然后再讨论更好的方法
// 这是一类标准的逆序数问题 看了一下discuss内容 貌似merge-sort比较帅
// https://siukwan.sinaapp.com/?p=1049
// 记录merge sort的过程中 右边交换到左边的个数
// 时间复杂度就是nlog(n)
// 用自定义数据结构 简化实现逻辑复杂度

class Solution {
public:
	struct node{
		int val; // 原来的value
		int cnt; // 在merge sort过程中移动到其左边的元素个数
		int idx; // 在原来数组中的index 用于生成结果
		node():val(0), cnt(0), idx(0){};
	};
	vector<int> countSmaller(vector<int>& nums){
		vector<int> ret(nums.size());
		// 引入新的数据结构
		vector<node> node_nums(nums.size());
		vector<node> tmp_node_nums(nums.size());
		for(int i=0; i<nums.size(); i++){
			node_nums[i].idx = i;
			node_nums[i].cnt = 0;
			node_nums[i].val = nums[i];
		}
		// 在新的数据结构下归并排序
		msort(node_nums, tmp_node_nums, 0, node_nums.size()-1);
		// 把tmp_node_nums中存的内容放到ret中
		for(int i=0; i<node_nums.size(); i++){
			ret[node_nums[i].idx] = node_nums[i].cnt;
		}
		return ret;
	}
	void msort(vector<node>& nums, vector<node>& tmp, int b, int e){
		// 递归实现merge sort的框架
		if(b>=e){return;}
		int m = (b+e)/2;
		msort(nums, tmp, b, m);
		msort(nums, tmp, m+1, e);
		// nums中应该是 b→m 和 m+1→e 都已经是有序的
		merge(nums, tmp, b, m, e);
	}
	void merge(vector<node>& nums, vector<node>& tmp, int l, int m, int r){
		// merge两个有序数组
		// left数组下标范围 l → m
		// right数组下标范围 m+1 → r
		int p1 = l;
		int p2 = m+1;
		int idx = l;
		// merge过程
		while(p1<=m && p2<=r){
			if(nums[p1].val <= nums[p2].val){
				// 精髓 轮到p1的时候 右边已经有p2-(m+1)个元素放到排序后的数组中了
				// 也就是p2-(m+1)个更小的元素出现在了p1的右边
				nums[p1].cnt += p2-(m+1);
				tmp[idx++] = nums[p1++];
			}
			else{
				tmp[idx++] = nums[p2++];
			}
		}
		// p1剩下了
		while(p1<=m){
			nums[p1].cnt += p2-(m+1);
			tmp[idx++] = nums[p1++];
		}
		// p2剩下了
		while(p2<=r){
			tmp[idx++] = nums[p2++];
		}
		for(int i=l; i<=r; i++){
			nums[i] = tmp[i];
		}
	}
};