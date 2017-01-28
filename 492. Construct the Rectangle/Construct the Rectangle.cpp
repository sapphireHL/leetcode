class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> result;
        int sq = sqrt(area) + 1;
        for(int i=sq; i>=1; i--){
            if(area % i == 0){
                result.push_back(i);
                result.push_back(area / i);
                break;
            }
        }
        if(result[0] < result[1]){
            int temp = result[0];
            result[0] = result[1];
            result[1] = temp;
        }
        return result;
    }
};
