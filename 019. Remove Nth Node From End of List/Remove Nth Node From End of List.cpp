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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *result = new ListNode(0);
        ListNode *p1 = result, *p2 = result;
        p1->next = head;
        for(int i=0; i<n; i++){
            p1 = p1->next;
        }
        while(p1->next != NULL){
            p1 = p1->next;
            p2 = p2->next;
        }
        p2->next = p2->next->next;
        return result->next;
    }
};
