#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct RandomListNode {
      int label;
      RandomListNode *next, *random;
      RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution{
public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
    	if ( !head ) return NULL;
		RandomListNode dummpy(-1);
		dummpy.next = head;
		RandomListNode *p1 = &dummpy;
		RandomListNode *p2 = head;
		// first round 
		map<RandomListNode*, RandomListNode*> oriNext;
		while (p2)
		{
			oriNext[p2] = p2->next;
			p1->next = new RandomListNode(p2->label);
			p1->next->random = p2;
			p2 = p2->next;
			p1->next->random->next = p1->next;
			p1 = p1->next;
		}
		// second round
		p1 = &dummpy;
		while ( p1 && p1->next )
		{
			p1->next->random = p1->next->random->random ? p1->next->random->random->next : NULL;
			p1 = p1->next;
		}
		// third round
		for ( map<RandomListNode*, RandomListNode*>::iterator i=oriNext.begin(); i!=oriNext.end(); ++i )
		{
			i->first->next = i->second;
		}
		return dummpy.next;
    }
};