class Solution {
public:
    bool isvalid(int hour, int minute, int count[]){
        if(count[hour/10] && count[hour%10] && count[minute/10] && count[minute%10])
            return true;
        return false;
    }
    
    string getRes(int i, int j){
        string res;
        if(i<10) res += "0";
        res += to_string(i) + ":";
        if(j<10) res += "0";
        res += to_string(j);
        return res;
    }
    
    string nextClosestTime(string time) {
        int count[10] = {0};
        for(int i=0; i<time.size(); i++){
            if(time[i] >= '0' && time[i] <= '9') count[time[i]-'0'] = 1;
        }
        int pos = time.find(':');
        int minute = stoi(time.substr(pos+1));
        int hour = stoi(time.substr(0, pos));
        string res;
        
        for(int i=hour; i<=23; i++){
            for(int j=0; j<=59; j++){
                if(i == hour && j > minute){
                    if(isvalid(i, j, count)){
                        return getRes(i, j);
                    }
                }
                else if(i > hour){
                    if(isvalid(i, j, count))
                        return getRes(i, j);
                }                    
            }
        }
        
        for(int i=0; i<=hour; i++){
            for(int j=0; j<=59; j++){
                if(i == hour && j <= minute){
                    if(isvalid(i, j, count))
                        return getRes(i, j);
                }
                else if(i < hour){
                    if(isvalid(i, j, count))
                        return getRes(i, j);
                }
            }
        }
    }
};
