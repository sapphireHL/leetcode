class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        sort(candies.begin(), candies.end());
        int n = candies.size();
        int m = distance(candies.begin(), unique(candies.begin(), candies.end()));
        cout<<n<<' '<<m;
        return m>=n/2?n/2:m;
    }
};
