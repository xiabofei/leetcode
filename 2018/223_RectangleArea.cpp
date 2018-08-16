#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://www.cnblogs.com/yrbbest/p/4993512.html
// 计算重复面积的简便方法 卡住left right top bottom各个位置

class Solution {
public:
    int computeArea(
    	int A, int B, int C, int D, 
    	int E, int F, int G, int H) {
    	// 两个矩形面积
    	int area = (C-A)*(D-B) + (G-E)*(H-F);
    	// 是否有overlap
    	if(A>=G || C<=E || B>=H || F>=D){
    		return area;
    	}
    	// 计算重叠
    	int overlap = (min(C,G)-max(A,E))*(min(D,H)-max(B,F));
    	return area - overlap;
    }
};