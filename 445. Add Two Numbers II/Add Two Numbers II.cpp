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
    int length(ListNode* l){
        ListNode *p = l;
        int res = 0;
        while(p!=NULL){
            res++;
            p = p->next;
        }
        return res;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *pr = result;
        stack<int> s, s2;
        int length1 = length(l1), length2 = length(l2);
        if(length1 > length2){
            int i=0; 
            while(i<length1-length2){
                s.push(p1->val);
                p1 = p1->next;
                i++;
            }
        }
        else if(length2 > length1){
            int i=0; 
            pr = result;
            while(i<length2-length1){
                s.push(p2->val);
                p2 = p2->next;
                i++;
            }
        }
        while(p1!=NULL){
            s.push(p1->val+p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            if(temp >= 10){
                temp -= 10;
                if(s.empty()){
                    s.push(1);
                }
                else
                    s.top()+=1;
            }
            s2.push(temp);
        }
        while(!s2.empty()){
            pr->next = new ListNode(s2.top());
            pr = pr->next;
            s2.pop();
        }
        return result->next;
    }
};
