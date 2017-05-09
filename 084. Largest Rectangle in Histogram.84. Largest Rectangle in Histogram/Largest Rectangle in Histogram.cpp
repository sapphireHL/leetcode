class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int result=0;
        stack<int> s;
        for(int i=0; i<heights.size(); ){
            if(s.empty() || heights[i] >= heights[s.top()])
                s.push(i++);
            else{
                int top=s.top();
                s.pop();
                result = max(result, heights[top]*(s.empty()?i:i-s.top()-1));
            }
        }
        return result;
    }
};
