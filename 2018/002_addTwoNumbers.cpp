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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* curr = new ListNode(0);
		ListNode* head = curr;
		int carry = 0;
		int digit = 0;
		while(l1 && l2){
			int tmp = l1->val + l2->val + carry;
			digit = tmp % 10;
			curr->next = new ListNode(digit);
			carry = tmp / 10;
			l1 = l1->next;
			l2 = l2->next;
			curr = curr->next;

		}
		if(l1||l2){
			ListNode* l = l1 ? l1 : l2;
			while(l){
				int tmp = l->val + carry;
				digit = tmp % 10;
				curr->next = new ListNode(digit);
				carry = tmp / 10;
				l = l->next;
				curr = curr->next;
			}
		}
		if(carry>0){
			curr->next = new ListNode(carry);
		}
		return head->next;
	}
};

int main(int argc, char const *argv[])
{
	/* code */
	return 0;
}