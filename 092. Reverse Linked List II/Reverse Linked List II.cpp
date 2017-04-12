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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *p = head, *last = head;
        for(int i=0; i<m-1; i++){
            last = p;
            p = p->next;
        }
        ListNode *pre = p;
        for(int i=0; i<n-m; i++){
            ListNode* next = pre->next;
            pre->next = next->next;
            next->next = p;
            p = next;
        }
        if(m == 1)
            return p;
        last->next = p;
        return head;
    }
};
