class Solution {
public:
    int addDigits(int num) {
        if (num % 9 == 0)
        {
            if (num == 0)
            return 0;
            else
            return 9;
        }
        else 
        return (num % 9);
    }
};
