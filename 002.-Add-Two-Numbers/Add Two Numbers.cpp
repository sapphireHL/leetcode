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
    	ListNode *pl1 = l1;
    	ListNode *pl2 = l2;
    	ListNode *res = new ListNode(0);
    	ListNode *p = res;
    	int up = 0;
    	while (pl1 != NULL && pl2 != NULL)
    	{
    	    p->next = new ListNode(0);
    		p->next->val = pl1->val + pl2->val + up;
    		up = 0;
    		if (p->next->val >= 10)
    		{
    			p->next->val -= 10;
    			up = 1;
    		}
    		pl1 = pl1->next;
    		pl2 = pl2->next;
    		p = p->next;
    	}
    	cout<<up<<endl;
    	if (pl1 != NULL){
    	    p->next = pl1;
    	    if(up == 1){
    	        pl1->val += 1;
    	        while(pl1->val >= 10){
    	            if(pl1->next == NULL){
    	                pl1->next = new ListNode(0);
    	            }
    	            pl1->val -= 10;
    	            pl1->next->val += 1;
    	            pl1 = pl1->next;
    	        }
    	    }
    	}
    	else if (pl2 != NULL){
    	    p->next = pl2;
    	    if(up == 1){
    	        pl2->val += 1;
    	        while(pl2->val >= 10){
    	            if(pl2->next == NULL){
    	                pl2->next = new ListNode(0);
    	            }
    	            pl2->val -= 10;
    	            pl2->next->val += 1;
    	            pl2 = pl2->next;
    	        }
    	    }
    	}
    	else{
    	    if(up == 1){
    	        p->next = new ListNode(1);
    	    }
    	}
    	return res->next;
    }
};
