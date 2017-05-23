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
    ListNode* merge2(ListNode* l1, ListNode*l2, ListNode* head){
        ListNode* cur = head;
        while(l1 && l2){
            if(l1->val <= l2->val){
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        cur->next = l1?l1:l2;
        while(cur->next) cur = cur->next;
        return cur;//返回末尾指针
    }
    ListNode* split(ListNode*head, int n){
        for(int i=1; i<n&&head; i++) head=head->next;
        if(!head) return NULL;
        ListNode* second = head->next;
        head->next = NULL;
        return second;
    }
    ListNode* sortList(ListNode* head) {
        //单链表归并排序，双向链表快速排序
        if(!head || !head->next) return head;
        int len=1;
        ListNode* p = head;
        for(; p->next; p = p->next) len++;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode*left, *right, *tail;
        for(int step=1; step<len; step*=2){
            p=dummy->next;
            tail = dummy;
            while(p){
                left=p;
                right = split(left, step);
                p = split(right, step);
                tail = merge2(left, right, tail);
            }
        }
        return dummy->next;
    }
};
