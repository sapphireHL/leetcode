class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = -1, minus  = 0, current = 0;
        for(int i=0; i<gas.size(); i++){
            current += gas[i] - cost[i];
            if(current >= 0){
                if(index == -1)
                    index = i;
            }
            else{
                index = -1;
                minus += current;
                current = 0;
            }
        }
        if(current + minus < 0) return -1;
        return index;
    }
};
