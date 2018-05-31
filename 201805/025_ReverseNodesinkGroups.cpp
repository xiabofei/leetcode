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
	ListNode* reverseKGroup(ListNode* head, int k) {
		if(k<=1){return head;}
		ListNode* headhead = new ListNode(0);
		headhead->next = head;
		ListNode* p1 = headhead;
		ListNode* p2 = headhead;
		while(p2){
			for(int i=0; i<k && p2; i++){
				p2 = p2->next;
			}
			if(p2){
				ListNode* tmpP1 = p1->next;
				ListNode* tmpP2 = p2->next;
				p2->next = NULL;
				p1->next = Solution::reverseList(p1->next);
				tmpP1->next = tmpP2;
				p1 = tmpP1;
				p2 = tmpP1;
			}
		}
		return headhead->next;
	}
	ListNode* reverseList(ListNode* head){
		ListNode* hh = new ListNode(0);
		hh->next = head;
		ListNode* p = head;
		while(p){
			ListNode* tmp = p->next;
			if(!tmp){break;}
			p->next = tmp->next;
			tmp->next = hh->next;
			hh->next = tmp;
		}
		return hh->next;
	}
};