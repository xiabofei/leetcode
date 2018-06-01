#include <vector>
#include <iostream>
#include <string>

using namespace std;

struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode *copyRandomList(RandomListNode *head) {
		if(!head){return head;}

		RandomListNode befor_head(0);
		befor_head.next = head;

        // 第一个pass: 创建新的node, 改造原node的next, A - A' - B - B' ...
		RandomListNode* p = head;
		while(p){
			RandomListNode* cp_node = new RandomListNode(p->label);
			RandomListNode* tmp = p->next;
			p->next = cp_node;
			cp_node->next = tmp;
			p = tmp;
		}

		// 第二个pass: 赋值新node的randomnode
		p = befor_head.next;
		RandomListNode copy_head(0);
		copy_head.next = p->next;
		while(p){
			if(p->random){
				p->next->random = p->random->next;
			}
			p = p->next->next;
		}

		// 第三个pass: 恢复两条链的next
		p = befor_head.next;
		while(p){
			RandomListNode* tmp = p->next;
			p->next = tmp->next;
			p = p->next;
			if(p){
				tmp->next = p->next;
			}
		}
		return copy_head.next;
	}
};

int main(int argc, char const *argv[])
{
	RandomListNode node(-1);
	Solution().copyRandomList(&node);
	return 0;
}