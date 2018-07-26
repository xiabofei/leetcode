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
    int countArrangement(int N) {
    	int cnt = 0;
    	unordered_set<int> used;
    	dfs(cnt, used, 1, N);
    	return cnt;
    }
    void dfs(int& cnt, unordered_set<int>& used, int pos, const int N){
    	if(pos>N){
    		cnt++;
    		return;
    	}
    	for(int i=1; i<=N; i++){
    		if(used.find(i)==used.end() && (i%pos==0 || pos%i==0) ){
    			used.insert(i);
    			dfs(cnt, used, pos+1, N);
    			used.erase(i);
    		}
    	}
    }
};