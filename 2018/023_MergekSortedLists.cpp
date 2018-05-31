#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	if(lists.size()==0){return NULL;}
    	return Solution::merge(lists, 0, lists.size()-1);
    }
    ListNode* merge(vector<ListNode*>& lists, int b, int e){
    	if(b==e){return lists[b];}
    	int m = (b+e)/2;
    	ListNode* left = Solution::merge(lists, b, m);
    	ListNode* right = Solution::merge(lists, m+1, e);
    	return Solution::merge2List(left, right);
    }
    ListNode* merge2List(ListNode* l1, ListNode* l2){
    	ListNode* head = new ListNode(0);
    	ListNode* curr = head;
    	while(l1 && l2){
    		if(l1->val < l2->val){
    			curr->next = l1;
    			l1 = l1->next;
    		}
    		else{
    			curr->next = l2;
    			l2 = l2->next;
    		}
    		curr = curr->next;
    	}
    	if(l1||l2){curr->next = l1 ? l1 : l2; }
    	return head->next;
    }
};