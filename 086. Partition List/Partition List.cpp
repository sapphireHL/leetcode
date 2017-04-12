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
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1), right_dummy(-1);
        ListNode *left = &left_dummy, *right = &right_dummy, *p = head;
        while(p){
            if(p->val < x){
                left->next = p;
                left = p;
            }
            else{
                right->next = p;
                right = p;
            }
            p = p->next;
        }
        left->next = right_dummy.next;
        right->next = NULL;
        return left_dummy.next;
    }
};
