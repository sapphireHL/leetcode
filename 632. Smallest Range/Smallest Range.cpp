class Solution {
public:
    struct number{
        int num, belong;
        number(int n=0, int b=0) : num(n), belong(b){}
    };
    
    static bool cmp(const number& a, const number& b){
        return a.num < b.num;
    }
    
    vector<int> smallestRange(vector<vector<int>>& nums) {
        map<int, int> mp;
        vector<number> allnum;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++)
                allnum.push_back(number(nums[i][j], i));
        }
        sort(allnum.begin(), allnum.end(), cmp);
        vector<int> count(nums.size());
        int left = 0, right = 0, minstart = 0, minrange = INT_MAX, range = 0;
        ////
        //slide window
        //////
        for(; right<allnum.size(); right++){
            if(count[allnum[right].belong] == 0) range++;
            count[allnum[right].belong]++;
            if(range == nums.size()){
                while(range == nums.size()){
                    if(count[allnum[left].belong] == 1) break;
                    else{
                        count[allnum[left].belong]--;
                        left++;
                    }
                }
                if(allnum[right].num - allnum[left].num < minrange){
                    minrange = allnum[right].num - allnum[left].num;
                    minstart = allnum[left].num;
                }
            }
        }
        vector<int> res(2);
        res[0] = minstart;
        res[1] = minstart + minrange;
        return res;
    }
};
