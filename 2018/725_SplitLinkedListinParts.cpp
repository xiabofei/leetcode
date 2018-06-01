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
	vector<ListNode*> splitListToParts(ListNode* root, int k) {
		vector<ListNode*> ret;
		ListNode* p = root;
		int length = 0;
		while(p){length++; p = p->next;}

		int avg_nodes = length/k;
		int num_addOne_components = length - k*avg_nodes;

		ListNode node(0);
		node.next = root;
		p = &node;
		ListNode* component_head = NULL;
		for(int i=1; i<=k; i++){
			ret.push_back(p->next);
			int component_length = avg_nodes;
			if(i<=num_addOne_components){component_length++;}
			for(int j=0; j<component_length; j++){p = p->next;}
			ListNode* tmp_p = new ListNode(0);
			tmp_p->next = p->next;
			p->next = NULL;
			p = tmp_p;
		}
		return ret;
	}
};

int main(int argc, char const *argv[])
{
	ListNode node1(1), node2(2), node3(2), node4(4), node5(0), node6(0), node7(0);
	node1.next = &node2;
	node2.next = &node3;
	node3.next = &node4;
	node4.next = &node5;
	node5.next = &node6;
	node6.next = &node7;
	Solution().splitListToParts(&node1, 3);
	return 0;
}