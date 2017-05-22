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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *dummy = new ListNode(INT_MIN);
        for(auto i=head; i; i=i->next){
            auto j=dummy, pre=dummy;
            for(; j&&i->val>=j->val; pre=j,j = j->next){}
            pre->next = new ListNode(i->val);
            pre->next->next = j;
        }
        return dummy->next;
    }
};
