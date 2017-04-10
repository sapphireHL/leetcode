class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // //Use a array to count how many times 1 appears in every bit, 
        // //then mod 3, the rest bit is the single number
        // int bitnum[32] = {0};
        // for(int i=0; i<32; i++){
        //     for(int j=0; j<nums.size(); j++){
        //         bitnum[i] += (nums[j]>>i) & 1;
        //     }
        //     bitnum[i] %= 3;
        // }
        // int result = 0;
        // for(int i=0; i<32; i++)
        //     result += bitnum[i]<<i;
        // return result;
        
        
        //ones represents how many bits one appear 1 time
        //twos represents how many bits one appear 2 times
        //threes represents how many bits one appear 3 times
        int ones = 0, twos = 0, threes = 0;
        for(int i=0; i<nums.size(); i++){
            twos |= ones & nums[i];
            ones ^= nums[i];
            threes = ones & twos;
            ones &= ~threes;
            twos &= ~threes;
        }
        return ones;
    }
};
