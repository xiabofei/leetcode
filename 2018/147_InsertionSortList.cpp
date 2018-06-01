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
    ListNode* insertionSortList(ListNode* head) {
    	if(!head || !head->next){return head;}
    	ListNode sorted_head(0);
    	// 把第一个节点加入sorted list
    	sorted_head.next = head;
    	ListNode* p = head->next;
    	head->next = NULL;
    	while(p){
    		// 每次插入p->val
    		ListNode* p1 = &sorted_head;
    		ListNode* p2 = sorted_head.next;
    		// 找到插入点
    		while(p2){
    			if(p2->val<=p->val){
    				p1 = p2;
    				p2 = p2->next;
    			}
    			else{
    				p1->next = p;
    				ListNode* tmp = p->next;
    				p->next = p2;
    				p = tmp;
    				break;
    			}
    		}
    		// 如果p2到了末尾
    		if(!p2){
    			p1->next = p;
    			ListNode* tmp = p->next;
    			p->next = NULL;
    			p = tmp;
    		}
    	}
    	return sorted_head.next;
    }
};