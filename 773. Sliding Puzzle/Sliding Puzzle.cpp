class Solution {
public:
    int dir[4][2] = {{-1,0}, {1,0},{0,-1},{0,1}};
    map<vector<vector<int>>, int> mp;
    
    bool check(vector<vector<int>>& board){
        if(board[0][0] == 1 && board[0][1] == 2 && board[0][2] == 3 && board[1][0] == 4 && board[1][1] == 5 && board[1][2] == 0)
            return true;
        return false;
    }
    
    int slidingPuzzle(vector<vector<int>>& board) {
        queue<vector<vector<int>>> q;
        q.push(board);
        int step = 0;
        
        while(!q.empty()){
            int size = q.size();
            for(int k = 0; k < size; k++){
                auto curboard = q.front();
                mp[curboard] = 1;
                q.pop();
                if(check(curboard)) 
                    return step;
                pair<int, int> zeropos;
                for(int i = 0; i < 2; i++){
                    for(int j = 0; j < 3; j++){
                        if(curboard[i][j] == 0){
                            zeropos.first = i;
                            zeropos.second = j;
                            break;
                        }
                    }
                }
                for(int i = 0; i < 4; i++){
                    pair<int, int> newpos(zeropos.first + dir[i][0], zeropos.second + dir[i][1]);
                    if(newpos.first < 0 || newpos.first >= 2 || newpos.second < 0 || newpos.second >= 3)
                        continue;
                    swap(curboard[zeropos.first][zeropos.second], curboard[newpos.first][newpos.second]);
                    if(!mp.count(curboard)){
                        mp[curboard] = 1;
                        q.push(curboard);
                    }
                    swap(curboard[zeropos.first][zeropos.second], curboard[newpos.first][newpos.second]);
                }
            }
            step++;
        }
        return -1;
    }
};
