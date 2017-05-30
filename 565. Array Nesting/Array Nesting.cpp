class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        vector<bool> use(n, false);
        for(int i=0; i<n; i++){
            if(!use[i]){
                use[i] = true;
                int cur = nums[i];
                int tmp = 1;
                while(cur != i){
                    use[cur] = true;
                    cur = nums[cur];
                    tmp++;
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};
