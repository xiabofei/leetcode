#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>

using namespace std	;

// 每个bar能顶多少水 由两个因素决定
// 1) left的最高bar
// 2) right的最高bar
// 1)和2)的最小值决定

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size()<=2){return 0;}
        const int len = height.size();
        // 找i左侧(包括i)的最大元素
        vector<int> left(len, 0);
        left[0] = height[0];
        for(int i=1; i<len; i++){left[i] = max(left[i-1], height[i]);}
        // 找i右侧(包括i)的最大元素
        vector<int> right(len, 0);
        right[len-1] = height[len-1];
        for(int i=len-2; i>=0; i--){right[i] = max(right[i+1], height[i]);}
        // 扫描 用累加的方式生成
        int ret = 0;
        for(int i=0; i<len; i++){
            ret += min(left[i], right[i])-height[i];
        }
        return ret;
    }
};