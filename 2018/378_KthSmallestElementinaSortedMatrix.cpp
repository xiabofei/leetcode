#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// http://www.cnblogs.com/grandyang/p/5727892.html
// 二分法
// 每次生成一个mid 从后往前遍历每一行 确定比mid小的个数
// 不断改变mid 直到left与right相等为止
// 为什么比mid小的时候 

// 这种部分有序的 尽量想办法利用有序的部分

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
    	const int rows = matrix.size();
    	const int cols = matrix[0].size();
    	int left = matrix[0][0];
    	int right = matrix[rows-1][cols-1];
    	while(left<right){
    		int mid = (left+right)/2;
    		int cnt = 0;
    		for(int r=0; r<rows; r++){
    			int c=cols-1;
    			while(c>=0 && matrix[r][c]>mid){c--;}
    			cnt += (c+1);
    		}
    		if(cnt<k){
    			left = mid+1;
    		}
    		else{
    			right = mid;
    		}
    	}
    	return left;
    }
};

