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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(!headA || !headB){return NULL;}
    	ListNode nodeA(0);
    	ListNode nodeB(0);
    	nodeA.next = headA;
    	nodeB.next = headB;
    	ListNode* pA = &nodeA;
    	ListNode* pB = &nodeB;

    	// 第一个pass 获得链表长度 并判断末尾节点是否相等
    	int lengthA = 0;
    	while(pA->next){lengthA++;pA = pA->next;}
    	int lengthB = 0;
    	while(pB->next){lengthB++;pB = pB->next;}
    	if(pA!=pB){return NULL;}

    	// 第二个pass 找到intersection的node
    	pA = &nodeA;
    	pB = &nodeB;
    	// A长A先走
    	if(lengthA>lengthB){
    		for(int i=0; i<lengthA - lengthB; i++){pA = pA->next;}
    	}
    	// B长B先走
    	if(lengthA<lengthB){
    		for(int i=0; i<lengthB - lengthA; i++){pB = pB->next;}
    	}
    	while(pA!=pB){pA = pA->next; pB = pB->next;}
    	return pA;
    }
};