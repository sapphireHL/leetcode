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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        while(l1 && l2){
            int val=0;
            if(l1->val<l2->val){val = l1->val; l1 = l1->next;}
            else {val = l2->val; l2 = l2->next;}
            p->next = new ListNode(val);
            p = p->next;
        }
        p->next = l1?l1:l2;
        return dummy->next;
    }
};
