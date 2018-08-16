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

class Solution {
public:
    string reverseVowels(string s) {
    	if(s.size()==0){return s;}
    	unordered_set<char> vowels = {'a','A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    	int p1 = 0;
    	int p2 = s.size();
    	while(p1<p2){
    		while(p1<p2 && vowels.find(s[p1])==vowels.end()){p1++;}
    		while(p1<p2 && vowels.find(s[p2])==vowels.end()){p2--;}
    		swap(s[p1], s[p2]);
    		p1++;
    		p2--;
    	}
    	return s;
    }
};