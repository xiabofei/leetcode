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
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    	unordered_set<string> wordDict(wordList.begin(), wordList.end());
    	unordered_map<string, int> distance;
    	// 用广搜算法建树 找到所有beginWord → endWord路径上的所有word到beginWord的距离
    	// distance差1相当于在图中两个word的联通的
    	bfs(beginWord, endWord, wordDict, distance);
    	vector<vector<string>> ret;
    	if(distance.find(endWord)==distance.end()){return ret;}
    	vector<string> tmp;
    	// 利用dfs回溯所有从 endWord → beginWord 的所有路径 
    	dfs(ret, tmp, distance, endWord);
    	return ret;
    }
    void bfs(string beginWord, string endWord, unordered_set<string>& wordDict, unordered_map<string, int>& distance){
    	queue<string> q;
    	distance[beginWord] = 0;
    	q.push(beginWord);
    	while(!q.empty()){
    		string curr = q.front();
    		q.pop();
    		for(int i=0; i<curr.size(); i++){
    			for(char c='a'; c<='z'; c++){
    				string next = curr;
    				next[i] = c;
    				// 剪枝 : 不在wordDict中 或者 已经找过这个词了
    				// 1) bfs先找到的路径一定是最短路径
    				// 2) 如果再通过其他路径找 使得next==endWord 会被后面的条件剪枝掉
    				// 因此就距离来说 一定是最短的距离
    				if(wordDict.find(next)==wordDict.end() || distance.find(next)!=distance.end()){
    					continue;
    				}
    				distance[next] = distance[curr] + 1;
    				q.push(next);
    			}
    		}
    	}
    }
    void dfs(vector<vector<string>>& ret, vector<string>& tmp, unordered_map<string, int>& distance, string curr){
    	tmp.push_back(curr);
    	if(distance[curr]==0){
    		vector<string> ladder(tmp);
    		reverse(ladder.begin(), ladder.end());
    		ret.push_back(ladder);
    		tmp.pop_back();
    		return;
    	}
    	for(int i=0; i<curr.size(); i++){
    		for(char c='a'; c<='z'; c++){
    			string next = curr;
    			next[i] = c;
    			if(distance.find(next) == distance.end() || distance[curr] != distance[next]+1){
    				continue;
    			}
    			dfs(ret, tmp, distance, next);
    		}
    	}
    	tmp.pop_back();
    }
};

int main(int argc, char const *argv[])
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> list = {"hot", "dot", "lot", "log", "cog"};
	vector<vector<string>> ret = Solution().findLadders(beginWord, endWord, list);
	cout << ret.size() << endl;
	return 0;
}