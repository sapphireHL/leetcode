class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const int n = letters.size();
        vector<int> dis(n, INT_MAX);
        for(int i=0; i<n; i++){
            if(target == letters[i]) continue;
            else if(target < letters[i]) dis[i] = letters[i] - target;
            else dis[i] = 26 + letters[i] - target;
        }
        char res;
        int min = INT_MAX;
        for(int i=0; i<n; i++){
            if(dis[i] < min){
                min = dis[i];
                res = letters[i];
            }
        }
        return res;
    }
};
