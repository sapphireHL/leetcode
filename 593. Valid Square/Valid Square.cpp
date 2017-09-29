class Solution {
public:
    int dis2(vector<int> p1, vector<int> p2){
        int x = p1[0] - p2[0];
        int y = p1[1] - p2[1];
        return (x*x + y*y);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p{p1, p2, p3, p4};
        unordered_set<int> edge;
        for(int i=0; i<4; i++){
            for(int j=0; j<4; j++){
                if(i == j) continue;
                int key = dis2(p[i], p[j]);
                edge.insert(key);
            }
        }
        if(edge.size() == 2){
            int num1 = *(edge.begin()), num2 = *(prev(edge.begin(), -1));
            if(num1 == 2*num2 || num2 == 2*num1) 
                return true;
        }
        return false;
    }
};
