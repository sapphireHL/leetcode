/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head) return NULL;
        RandomListNode *newhead = new RandomListNode(0), *p = head, *newp = newhead;
        while(p){
            RandomListNode *value = new RandomListNode(p->label);
            value->next = p->next;
            p->next = value;
            p = value->next;
        }
        p = head;
        while(p){
            if(p->random != NULL){
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = head, newp = newhead;
        while(p){
            newp->next = p->next;
            newp = newp->next;
            p->next = p->next->next;
            p = p->next;
        }
        return newhead->next;
    }
};
