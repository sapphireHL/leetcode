/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0, lengthB = 0;
        bool isfind = 0;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while(pa != NULL){
            lengthA++;
            pa = pa->next;
        }
        while(pb != NULL){
            lengthB++;
            pb = pb->next;
        }
        pa = headA;
        pb = headB;
        if(lengthA > lengthB){
            for(int i=0; i<lengthA-lengthB; i++){
                pa = pa->next;
            }
        }
        else{
            for(int i=0; i<lengthB-lengthA; i++){
                pb = pb->next;
            }
        }
        while(pa != NULL){
            if(pa == pb){
                isfind = 1;
                break;
            }
            pa = pa->next;
            pb = pb->next;
        }
        if(isfind){
            return pa;
        }
        return NULL;
    }
};
