class Solution {
public:
    int num[10001];
    //int dp1[10001];//取
    //int dp2[10001];//不取
    int skip = 0, take = 0;
    int deleteAndEarn(vector<int>& nums) {
        for(int i:nums)
            num[i]++;
        for(int i = 1; i <= 10000; i++){
            if(num[i] == 0){
                //dp2[i] = max(dp1[i-1], dp2[i-1]);
                skip = max(skip, take);
                continue;
            }
            int tmp = take;
            take = skip + i * num[i];
            skip = max(tmp, skip);
            //dp1[i] = dp2[i-1] + i*num[i];
            //dp2[i] = max(dp1[i-1], dp2[i-1]);
        }
        return max(skip, take);
    }
};
