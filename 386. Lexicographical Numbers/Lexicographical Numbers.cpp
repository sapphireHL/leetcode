class Solution {
public:
    vector<int> res;
    
    void dfs(int cur, int n) {
        if (cur > n) {
            return;
        }
        int end = min(n, cur / 10 * 10 + 9);
        for (int i = cur; i <= end; i++) {
            res.push_back(i);
            dfs(10 * i, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        dfs(1, n);
        return res;
    }
};
