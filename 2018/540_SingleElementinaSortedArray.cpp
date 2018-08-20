#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;

// https://blog.csdn.net/Lakers_KobeBryant/article/details/71486830
// https://blog.csdn.net/pessis1/article/details/76222579
// 题目特点 所有的都出现了twice 只有一个出现了once
// 包含target的长度一定是奇数长度的 每次可以排除的一定是偶数长度的那段
// 因此这是二分查找的基石
// 1) 如果m与l和r都不同 则m就是需要找的
// 2) m是偶数(m代表index) 则一定得与m+1相等才能排除前m个; 同理 m是奇数时 则一定与m-1相等才能排除前m个
// 3) 剩余的情况就是 后面len-m个一定可以被排除了

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    	if(nums.size()==1){return nums[0];}
    	int l = 0;
    	int r = nums.size();
    	while(l<r){
    		int m = (l+r)/2;
    		if(nums[m]!=nums[m+1] && nums[m]!=nums[m-1]){
    			return nums[m];
    		}
    		else if( (!(m&1) && nums[m]==nums[m+1]) || (m&1 && nums[m]==nums[m-1])){
    			l = m + 1;
    		}
    		else{
    			r = m - 1;
    		}
    	}
    	return nums[l];
    }
};