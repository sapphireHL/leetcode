class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res, table(n+1);
        for(int i=0; i<n; i++){
            table[nums[i]]++;
            if(table[nums[i]] == 2) {
                res.push_back(nums[i]);
            }
        }
        for(int i=1; i<=n; i++){
            if(table[i] == 0){
                res.push_back(i);
                break;
            }
        }
        return res;
    }
};
