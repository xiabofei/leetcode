#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>

using namespace std;

// https://www.jianshu.com/p/392765038d89
// unordered_set的实现类似Hashmap
// 插入 查找 删除的时间复杂度都为常量

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    	if(s.size()==0){return 0;}
    	unordered_set<char> occur;
    	int p1=0;
    	int p2=1;
    	int longest = 1;
    	occur.insert(s[p1]);
    	while(p2<s.size()){
    		if(occur.find(s[p2])!=occur.end()){
    			occur.erase(s[p1]);
    			p1++;
    		}
    		else{
    			occur.insert(s[p2]);
    			longest = max(longest, (int)occur.size());
    			p2++;
    		}
    	}
    	return longest;
    }
};