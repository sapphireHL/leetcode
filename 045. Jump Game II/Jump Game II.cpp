class Solution {
public:
    int jump(vector<int>& nums) {
        //记录到达各个点的最小步数
        vector<int> step(nums.size(), 0);
        //记录当前能达到的最远点,上一个最远点
        int maxstep = 0, laststep = 0;
        for(int i=0; i<nums.size()-1; i++){
            if(i+nums[i] > maxstep) {laststep = maxstep; maxstep = i+nums[i];}
            //如果当前走不到比当前最远点更远，就不处理
            else continue;
            for(int j=laststep+1; j<nums.size() && j<=maxstep; j++){
                step[j] = step[i]+1;
            }
            if(maxstep>=nums.size()-1) break;
        }
        return step[nums.size()-1];
    }
};
