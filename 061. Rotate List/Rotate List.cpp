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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *p = head;
        int length = 1;
        while(p->next){
            length++;
            p = p->next;
        }
        //首尾相连
        p->next = head;
        for(int i=0; i<length-k%length; i++){
            p = p->next;
        }
        ListNode *result = p->next;
        p->next = NULL;
        return result;
    }
};
