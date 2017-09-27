/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack<TreeNode *> stk;
    BSTIterator(TreeNode *root) {
        TreeNode * p = root;
        while(p){
            stk.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return stk.size() > 0;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = stk.top();
        stk.pop();
        if(cur->right){
            TreeNode*p = cur->right;
            while(p){
                stk.push(p);
                p = p->left;
            }
        }
        return cur->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
