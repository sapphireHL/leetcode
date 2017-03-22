/**ou 
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
        ListNode *current = head, *p = head, *result = head;
        while(p != NULL){
            if(p->val != current->val){
                current->next = p;
                current = current->next;
            }
            p = p->next;
        }
        current->next = NULL;
        return result;
    }
};
