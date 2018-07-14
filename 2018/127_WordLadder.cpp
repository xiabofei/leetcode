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
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		// bfs
		unordered_map<string, int> distance;
		distance[beginWord] = 1;
		queue<string> q;
		q.push(beginWord);
		while(!q.empty()){
			string curr = q.front();
			q.pop();
			for(int i=0; i<curr.size(); i++){
				for(char l = 'a'; l <='z'; l++){
			        string next = curr;
					next[i] = l;
					if(dict.find(next)==dict.end() || distance.find(next)!=distance.end()){
						continue;
					}
					distance[next] = distance[curr] + 1;
					if(next==endWord){
						return distance[endWord];
					}
					q.push(next);
				}
			}
		}
		return distance[endWord];
	}
};

int main(int argc, char const *argv[])
{
	string b = "hit";
	string e = "cog";
	vector<string> dat = {"hot", "dog", "lot", "log", "cog"};
	cout << Solution().ladderLength(b, e, dat) << endl;
	return 0;
}