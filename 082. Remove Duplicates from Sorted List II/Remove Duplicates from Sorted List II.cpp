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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode *p = head, *current = new ListNode(0), *result = current;
        while(p != NULL && p->next != NULL){
            if(p->val == p->next->val){
                int cur = p->val;
                while(p != NULL && p->val == cur)
                    p = p->next;
                if(p == NULL)
                    current->next = NULL;
            }
            else{
                current->next = p;
                current = current->next;
                p = p->next;
            }
        }
        if(p != NULL)
            current->next = p;
        return result->next;
    }
};
