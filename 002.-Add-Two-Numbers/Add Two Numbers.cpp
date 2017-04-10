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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	ListNode *p1 = l1, *p2 = l2, *res = new ListNode(0), *p = res;
    	int carry = 0;
    	while(p1 != NULL || p2 != NULL){
    	    int v1 = (p1 == NULL ? 0 : p1->val);
    	    int v2 = (p2 == NULL ? 0 : p2->val);
    	    int v = (v1 + v2 + carry) % 10;
    	    carry = (v1 + v2 + carry) / 10;
    	    p->next = new ListNode(v);
    	    if(p1 != NULL) p1 = p1->next;
    	    if(p2 != NULL) p2 = p2->next;
    	    p = p->next;
    	}
    	if(carry > 0) p->next = new ListNode(1);
    	return res->next;
    }
};
