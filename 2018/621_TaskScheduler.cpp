#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;


// http://www.cnblogs.com/grandyang/p/7098764.html
// 先处理高频任务 再处理低频任务
// 这里只需要找到最高频的任务 及其频率
// 比较复杂的部分是需要处理多个任务都是高频任务的内容

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
    	vector<int> cnts(26, 0);
    	// 任务频率相等的最高频有几个 频率是多少 
    	for(int i=0; i<tasks.size(); i++){
    		cnts[tasks[i]-'A']++;
    	}
    	int max_freq = 0;
    	int same_max = 0;
    	for(int i=0; i<26; i++){
    		if(max_freq == cnts[i]){
    			same_max++;
    		}
    		else if(max_freq < cnts[i]){
    			max_freq = cnts[i];
    			same_max = 1;
    		}
    	}
    	int ret = 0;
    	// 如果slots大于task_left则必须补idle
    	// 如果slots小于task_left则不需要补idle
    	int task_left = tasks.size() - max_freq * same_max;
    	int slots = (n + 1 - same_max) * (max_freq-1);
    	ret = max(0, slots - task_left) + tasks.size();
    	return ret;
    }
};

int main(int argc, char const *argv[])
{
	vector<char> dat = {'A','A','A','B','B','B'};
	Solution().leastInterval(dat, 2);
	return 0;
}