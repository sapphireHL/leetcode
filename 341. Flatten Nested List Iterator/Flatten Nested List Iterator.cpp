/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> num;
    int pos;
    queue<int> q;
    
    void dfs(vector<NestedInteger>& list){
        for(int i=0; i<list.size(); i++){
            if(list[i].isInteger())
                num.push_back(list[i].getInteger());
            else
                dfs(list[i].getList());
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        pos = 0;
        dfs(nestedList);
    }

    int next() {
        return num[pos++];
    }

    bool hasNext() {
        return pos < num.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
