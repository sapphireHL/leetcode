class Solution {
public:
    int maxArea(vector<int>& height) {
        int res=0, left = 0, right = height.size()-1;
        while(left < right){
            int h=min(height[left], height[right]);
            res = max(res, h*(right-left));
            if(height[left] < height[right]) left++;
            else right--;
        }
        return res;
    }
};
