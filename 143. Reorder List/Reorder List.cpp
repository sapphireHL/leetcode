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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while (head) {
            ListNode* next = head -> next;
            head -> next = pre;
            pre = head;
            head = next;
        } 
        return pre;
    }
    
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode *slow = head, *fast = head, *pre = head;
        //Find the middle node
        while(fast && fast->next){
            pre = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        //Split the node
        pre->next = NULL;
        //Reverse
        slow = reverseList(slow);
        //Merge
        while(head && slow){
            ListNode * next1 = head->next;
            ListNode * next2 = slow->next;
            head->next = slow;
            if(next1)
                slow->next = next1;
            head = next1;
            slow = next2;
        }
    }
};
