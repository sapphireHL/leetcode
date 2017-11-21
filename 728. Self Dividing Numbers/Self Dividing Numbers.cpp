class Solution {
public:
    bool isvalid(int num){
        int tmp = num;
        while(tmp != 0){
            int mod = tmp % 10;
            if(mod == 0) return false;
            if(num % mod != 0) return false;
            tmp /= 10;
        }
        return true;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; i++){
            if(isvalid(i))
                res.push_back(i);
        }
        return res;
    }
};
