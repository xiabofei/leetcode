#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// 直观想法
// 		扩展A 比如 A 3×3 → 9×9
// 		B的起点移动 保证B在9×9这个框里面

// 转换思路
// 		保存为1的二维坐标点 以二者差的坐标为key
//		(r1-r2, c1-c2) 坐标差相同的就是overlap
// 		c++不能直接用pair<int, int>作为key 因此要转变为1D坐标

class Solution {
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
    	const int rows = A.size();
    	if(rows==0){return 0;}
    	const int cols = A[0].size();
    	vector<int> coor_A;
    	vector<int> coor_B;
    	// 保存1的坐标点
    	for(int i=0; i<rows*cols; i++){
    		if(A[i/rows][i%cols]){
    			coor_A.push_back(i/rows*1000+i%cols);
    		}
    		if(B[i/rows][i%cols]){
    			coor_B.push_back(i/rows*1000+i%cols);
    		}
    	}
    	// 用hashmap 1D的index gap为key value为1的个数
    	unordered_map<int, int> gap_ones;
    	for(int i=0; i<coor_A.size(); i++){
    		for(int j=0; j<coor_B.size(); j++){
    			gap_ones[coor_A[i]-coor_B[j]]++;
    		}
    	}
    	int ret = 0;
    	for(auto it: gap_ones){
    		ret = max(ret, it.second);
    	}
    	return ret;
    }
};