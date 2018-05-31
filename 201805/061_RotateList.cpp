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
    ListNode* rotateRight(ListNode* head, int k){
    	if(k==0 || !head){return head;}
    	int len = 0;

    	ListNode* tmp = new ListNode(0);
    	tmp->next = head;
    	while(tmp->next){len++; tmp=tmp->next;}
    	k = k % len;
    	if(k==0){return head;}

    	ListNode* hh = new ListNode(0);
    	ListNode* p1 = new ListNode(0);
    	ListNode* p2 = new ListNode(0);
    	hh->next = head;
    	p1 = hh;
    	p2 = hh;
    	for(int i=0; i<k; i++){p2 = p2->next; }
    	while(p2 && p2->next){
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    	ListNode* tmp2 = hh->next;
    	hh->next = p1->next;
    	p1->next = NULL;
    	p2->next = tmp2;
    	return hh->next;
    }
};
