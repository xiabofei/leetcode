#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// 题意
//  目标是要把n个1填进去
// 	1的不能占 0可以占
//	不能出现连续两个1
// 解法
// 	采用贪心算法 遇上能种的就种上

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    	// 处理花槽长度是0和1的情况
    	if(flowerbed.size()==0){return n==0;}
    	if(flowerbed.size()==1){return n==0 || n==1 && flowerbed[0]==0;}
    	// 花槽长度至少是2
    	int num_placed = 0;
    	// 单处理index==0的情况
    	if(flowerbed[0]==0 && flowerbed[1]==0){
    		flowerbed[0] = 1;
    		num_placed++;
    		if(num_placed>=n){return true;}
    	}
    	int idx = 2;
    	while(idx<flowerbed.size()-1){
    		if(flowerbed[idx]==1){
    			idx += 2;
    		}
    		else{
    			if(flowerbed[idx-1]==0 && flowerbed[idx+1]==0){
    				flowerbed[idx] = 1;
    				num_placed++;
    				if(num_placed>=n){return true;}
    				idx += 2;
    			}
    			else{
    				idx += 1;
    			}
    		}
    	}
    	// 单独处理index==flowerbed.size()-1的情况
    	if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2]==0){
    		num_placed++;
    	}
    	return num_placed>=n;
    }
};