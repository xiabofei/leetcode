#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
    	// 数字转化为数组
    	int ori = num;
    	vector<int> digits;
    	while(num>0){
    		digits.push_back(num % 10);
    		num = num / 10;
    	}
    	if(digits.size()==1){return ori;}
    	reverse(digits.begin(), digits.end());
    	// 构造原来digits能构成的最大数字largest
    	vector<int> largest = digits;
    	sort(largest.begin(), largest.end());
    	reverse(largest.begin(), largest.end());
    	// 比较digits和largest
    	int left_pos = -1;
    	for(int i=0; i<digits.size(); i++){
    		if(digits[i] != largest[i]){
    			left_pos = i;
    			break;
    		}
    	}
    	// 已经是最大 返回原数字
    	if(left_pos==-1){return ori;}
    	int right_pos = digits.size();
    	for(int i=digits.size()-1; i>0; i--){
    		if(digits[i]==largest[left_pos]){
    			right_pos = i;
    			break;
    		}
    	}
    	swap(digits[left_pos], digits[right_pos]);
    	int ret = 0;
    	for(int i=0; i<digits.size(); i++){
    		ret = 10*ret + digits[i];
    	}
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	Solution().maximumSwap(9973);
	return 0;
}