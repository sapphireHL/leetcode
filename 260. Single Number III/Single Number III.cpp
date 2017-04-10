class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    //by XORing all the numbers, we actually get the XOR of the two target numbers
    //because XORing two duplicate numbers always results in 0.
    //Consider the XOR result of the two target numbers; if some bit of the XOR result is 1, 
    //it means that the two target numbers differ at that location.
    //Thus, all the numbers can be partitioned into two groups according to their bits at location i.
    //the first group consists of all numbers whose bits at i is 0.
    //the second group consists of all numbers whose bits at i is 1.
    //by XoRing all numbers in the first group, we can get the first number.
    //by XoRing all numbers in the second group, we can get the second number.
        int dif = 0;
        for(int i=0; i<nums.size(); i++)
            dif ^= nums[i];
        dif &= -dif;
        vector<int> result(2, 0);
        for(int i=0; i<nums.size(); i++){
            if((nums[i] & dif) == 0)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        return result;
    }
};
