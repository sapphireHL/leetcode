class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, size = height.size();
        vector<int> maxleft(size, 0);
        vector<int> maxright(size, 0);
        for(int i=1; i<size; i++){
            maxleft[i] = max(maxleft[i-1], height[i-1]);
            maxright[size-i-1] = max(maxright[size-i], height[size-i]);
        }
        for(int i=1; i<size-1; i++){
            if(min(maxleft[i], maxright[i]) > height[i])
                result += min(maxleft[i], maxright[i]) - height[i];
        }
        return result;
    }
};
