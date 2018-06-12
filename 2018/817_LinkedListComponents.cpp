#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
    	if(!head){return 0;}
    	unordered_set<int> setG(G.begin(), G.end());
    	ListNode node(-1);
    	node.next = head;
    	ListNode* p1 = &node;
    	ListNode* p2 = head;
    	int ret = 0;
    	while(p2){
    		if(setG.count(p2->val)==0 && setG.count(p1->val)>0){
    			ret++;
    		}
    		p1 = p2;
    		p2 = p2->next;
    	}
    	if(setG.count(p1->val)>0){ret++;}
    	return ret;
    }
};