#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
    	if(s1.size()>s2.size()){return false;}
    	// 统计一遍s1中字母的数量
    	vector<int> cnt_s1(26, 0);
    	for(int i=0; i<s1.size(); i++){cnt_s1[s1[i]-'a']++;}
    	// 统计一遍s2中字母的数量
        vector<int> cnt_s2(26, 0);
    	int p1 = 0;
    	int p2 = s1.size()-1;
    	for(int i=p1; i<=p2; i++){cnt_s2[s2[i]-'a']++;}
    	// 比较s1和s2的count是否相等
    	while(p2<s2.size()){
    		if(match(cnt_s1, cnt_s2)){
    			return true;
    		}
    		cnt_s2[s2[p1]-'a']--;
    		p1++;
    		p2++;
    		cnt_s2[s2[p2]-'a']++;
    	}
    	return false;
    }
    bool match(vector<int>& cnt1, vector<int>& cnt2){
    	for(int i=0; i<26; i++){
    		if(cnt1[i]!=cnt2[i]){
    			return false;
    		}
    	}
    	return true;
    }
};