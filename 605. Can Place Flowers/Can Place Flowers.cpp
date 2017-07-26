class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int maxf = 0, i = 0, zeros = 0;
        while(i < flowerbed.size() && flowerbed[i] == 0) i++;
        if(i == flowerbed.size()) return (flowerbed.size()+1)/2 >= n;
        maxf += (i)/2;
        while(i<flowerbed.size()){
            if(flowerbed[i] == 1){
                maxf += (zeros-1)/2;
                zeros = 0;
            }
            else {
                zeros++;
                if(i == flowerbed.size()-1) maxf += zeros/2;
            }
            i++;
        }
        return maxf >= n;
    }
};
