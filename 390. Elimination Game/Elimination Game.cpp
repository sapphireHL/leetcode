class Solution {
public:
    int lastRemaining(int n) {
        int head = 1, remain = n, left = 1, step = 1;
        while(remain > 1){
            if(left){
                head += step;
            }
            else{
                if(remain % 2 == 1){
                    head += step;
                }
            }
            left = !left;
            step *= 2;
            remain /= 2;
        }
        return head;
    }
};
