class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        string res;
        long long nume = (long long)numerator, deno = (long long)denominator;
        //符号
        if((nume < 0 && deno > 0) || (nume > 0 && deno < 0))
            res += '-';
        nume = abs(nume);
        deno = abs(deno);
        
        //整数部分
        long long num = nume / deno;//-2147483648 -1溢出
        res += to_string(num);
        nume %= deno;
        if(nume == 0) return res;
        
        //小数部分
        res += '.';
        unordered_map<int, int> mp;
        int index = res.size();
        mp[nume] = index++;
        while(nume != 0){
            int cur = nume * 10 / deno;
            nume = nume * 10 % deno;
            res += to_string(cur);
            if(mp.count(nume)){
                int pos = mp[nume];
                res.insert(pos, "(");
                res += ')';
                break;
            }
            mp[nume] = index++;
        }
        return res;
    }
};
