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
    ListNode* partition(ListNode* head, int x) {
    	ListNode node_less(0);
    	ListNode node_large(0);
    	ListNode* pless = &node_less;
    	ListNode* plarge = &node_large;
    	while(head){
    		if(head->val<x){
    			pless->next = head;
    			pless = pless->next;
    		}
    		else{
    			plarge->next = head;
    			plarge = plarge->next;
    		}
    		head = head->next;
    	}
    	pless->next = node_large.next;
    	return node_less.next;
    }
};