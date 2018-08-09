#include <vector>
#include <iostream>
#include <string>

using namespace std;

// 1) p1和p2往前移动的时候都留一个富余
// 2) 当p1->next与p2->next不等的时候 看看p1和p2是否挨着 判断是否要留下来
// 3) 退出时候再判断一把

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head){return head;}
    	ListNode* headhead = new ListNode(0);
    	headhead->next = head;
    	ListNode* p1 = headhead;
    	ListNode* p2 = headhead;
    	while(p2->next){
    		if(p1->next->val!=p2->next->val){
    			if(p1->next==p2){
    				p1 = p1->next;
    			}
    			else{
    				p1->next = p2->next;
    			}
    		}
    		p2 = p2->next;
    	}
    	if(p1->next!=p2){
    		p1->next = NULL;
    	}
    	return headhead->next;
    }
};