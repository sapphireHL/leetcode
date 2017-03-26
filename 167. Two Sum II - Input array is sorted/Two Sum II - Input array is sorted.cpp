class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> m;
        for(int i=0; i<nums.size(); i++)
            m[nums[i]] = i;
        for(int i=0; i<nums.size(); i++){
            int gap = target - nums[i];
            if(m.find(gap) != m.end() && m[gap] > i){
                res.push_back(i);
                res.push_back(m[gap]);
                break;
            }
        }
        return res;
    }
};


///////////////////////////////////////////////////////////
//approach method
///////////////////////////////////////////////////////////
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int left = 0, right = numbers.size()-1;
        while(left < right){
            if(numbers[left]+numbers[right] == target){
                res.push_back(left+1);
                res.push_back(right+1);
                break;
            }
            else if(numbers[left]+numbers[right] > target)
                right--;
            else
                left++;
        }
        return res;
