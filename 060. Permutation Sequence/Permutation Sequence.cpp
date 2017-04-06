class Solution {
public:
    int factorial(int n){
        if(n > 1)
            return n*factorial(n-1);
        else
            return 1;
    }
    string getPermutation(int n, int k) {
        string result;
        vector<int> seq;
        k--;
        for(int i=0; i<n; i++)
            seq.push_back(i+1);
        for(int i=n-1; i>0; i--){
            int base = factorial(i);
            int num = k / base;
            k %= base;
            result += '0'+seq[num];
            seq.erase(next(seq.begin(), num));
        }
        result += '0' + seq[0];
        return result;
    }
};
