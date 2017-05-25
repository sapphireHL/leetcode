class Solution {
public:
    string tostring(int add){
        int hour = add/60;
        int mi = add%60;
        string res;
        if(hour>11) return "";
        char c[20];
        if(mi<10) sprintf(c, "%d:0%d", hour, mi);
        else sprintf(c, "%d:%d", hour, mi);
        res = c;
        return res;
    }
    void dfs(int *table, vector<string>&res, int &count, int &add, int start, int num){
        //分钟不能超过59
        if(add > 59 && start <= 6) {return;}
        if(count == num){
            if(tostring(add)!="") res.push_back(tostring(add));
            return;
        }
        for(int i=start; i<10; i++){
            count++;
            add += table[i];
            dfs(table, res, count, add, i+1, num);
            count--;
            add -= table[i];
        }
    }
    vector<string> readBinaryWatch(int num) {
        int minutes[10] = {1, 2, 4, 8, 16, 32, 60, 120, 240, 480};
        vector<string> res;
        int count = 0, add = 0;
        dfs(minutes, res, count, add, 0, num);
        return res;
    }
};
