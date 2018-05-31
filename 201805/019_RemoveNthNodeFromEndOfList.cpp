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
    ListNode* removeNthFromEnd(ListNode* head, int n){
    	if(!head){return head;}
    	ListNode* p1 = new ListNode(0);
    	ListNode* p2 = new ListNode(0);
    	p1->next = head;
    	p2->next = head;
    	// 留一个dump 不能直接返回head 因为删除的可能是head
    	ListNode* dump = p1;
    	for(int i=0; i<n; i++){p2 = p2->next;}
    	while(p2->next){
    		p1 = p1->next;
    		p2 = p2->next;
    	}
    	// 链表删除操作 p->next = p->next->next
    	p1->next = p1->next->next;
    	return dump->next;
    }
};