class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int max = INT_MIN;
        int count = 1;
        vector<string> result(nums.size());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > max){
                max = nums[i];
            }
        }
        vector<int> rank(max+1, -1);
        for(int i=0; i<nums.size(); i++){
            rank[nums[i]] = i;
        }
        for(int i=rank.size()-1; i>=0; i--){
            if(rank[i] != -1){
                if(count == 1){
                    result[rank[i]] = "Gold Medal";
                    count++;
                }
                else if(count == 2){
                    result[rank[i]] = "Silver Medal";
                    count++;
                }
                else if(count == 3){
                    result[rank[i]] = "Bronze Medal";
                    count++;
                }
                else{
                    stringstream ss;
                    string s;
                    ss << count++;
                    ss >> s;
                    result[rank[i]] = s;
                }
            }
        }
        return result;
    }
};
