#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <map>
#include <set>

using namespace std;


// 基础思路是分类讨论 
// http://www.cnblogs.com/grandyang/p/5849037.html

class Solution {
public:
	string decodeString(string s) {
		stack<string> sta_str;
		stack<int> sta_times;
		int times = 0;
		string curr = ""; // curr的意义是 sta_times栈顶元素对应的字符串
		int i = 0;
		while(i<s.size()){
			if(s[i]>='0' && s[i]<='9'){
				times = times*10 + s[i] - '0';
			}
			if(s[i]=='['){
				// 比如 3[a2[c]]
				// times为3入栈时 curr为"" 相当于先垫一个str的位置
				// 二者一起入栈 保持入栈的模式为 数字 + 字符串
				sta_str.push(curr);
				curr.clear();
				sta_times.push(times);
				times = 0;
			}
			if(s[i]==']'){
				// 需要出栈时
				// curr对应的times就是sta_times的栈顶元素
				// times出栈 再用把curr与sta_str的栈顶元素累加
				// sta_str栈顶元素出栈
				int k = sta_times.top();
				sta_times.pop();
				for(int j=0; j<k; ++j){
					sta_str.top() += curr;
				}
				curr = sta_str.top();
				sta_str.pop();
			}
			if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
				curr.push_back(s[i]);
			}
			i++;
		}
		return curr;
	}
};

int main(int argc, char const *argv[])
{
	string s = "3[a2[c]]";
	cout << Solution().decodeString(s) << endl;
	return 0;
}