class Solution {
public:
    vector<int> constructArray(int n, int k) {
        //1, k+1, 2, k, 3, k-1, 4, k-1 ……
        int left = 1, right = k+1;
        vector<int> res;
        while(left <= right){
            if(left == right) res.push_back(left);
            else{
                 res.push_back(left);
                 res.push_back(right);
            }
            left++;
            right--;
        }
        for(int i=k+2; i<=n; i++) res.push_back(i);
        return res;
    }
};
