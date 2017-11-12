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
    int length(ListNode* root){
        auto p = root;
        int len = 0;
        while(p){
            len++;
            p = p->next;
        }
        return len;
    }
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        vector<int> perlen(k);
        int len = length(root);
        for(int i=0; i<k; i++){
            perlen[i] += len / k;
        }
        for(int i=0; i<len%k; i++){
            perlen[i]++;
        }
        auto p = root;
        for(int i=0; i<k; i++){
            if(perlen[i] == 0){
                res.push_back(nullptr);
                continue;
            }
            ListNode* dummy = p;
            while(perlen[i] - 1 > 0){
                p = p->next;
                perlen[i]--;
            }
            ListNode * tmp = p;
            p = p->next;
            tmp->next = nullptr;
            res.push_back(dummy);
        }
        return res;
    }
};
