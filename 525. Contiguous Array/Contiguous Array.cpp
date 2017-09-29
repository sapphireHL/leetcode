class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int maxlen = 0, count = 0;
        unordered_map<int, int> table;//key -- first index
        table[0] = -1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0) count--;
            else count++;
            if(table.count(count))
                maxlen = max(maxlen, i-table[count]);
            else
                table[count] = i;
        }
        return maxlen;
    }
};
