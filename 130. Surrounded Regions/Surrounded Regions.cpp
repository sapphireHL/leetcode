class Solution {
public:
	struct point
	{
		int x, y;
		point(int xx, int yy) :x(xx), y(yy){}
	};

	int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

	void solve(vector<vector<char>>& board) {
		const int m = board.size();
		if (m == 0) return;
		const int n = board[0].size();
        if(m <= 2 || n <= 2) return;
		//与边界相邻的O保留
		queue<point> q;
		for (int j = 0; j < n - 1; j++){
			if (board[0][j] == 'O') q.push(point(0, j));
		}
		for (int i = 0; i < m - 1; i++){
			if (board[i][n - 1] == 'O') q.push(point(i, n - 1));
		}
		for (int j = n - 1; j > 0; j--){
			if (board[m - 1][j] == 'O') q.push(point(m - 1, j));
		}
		for (int i = m - 1; i>0; i--){
			if (board[i][0] == 'O') q.push(point(i, 0));
		}
		//bfs
		vector<vector<int>> visit(m, vector<int>(n));
		while (!q.empty()){
			point cur = q.front();
			q.pop();
			if (visit[cur.x][cur.y]) continue;
			visit[cur.x][cur.y] = 1;
			//加入相邻的O
			for (int i = 0; i < 4; i++){
				int nextx = cur.x + dir[i][0], nexty = cur.y + dir[i][1];
				if (nextx >= 0 && nextx < m && nexty >= 0 && nexty < n && !visit[nextx][nexty] && board[nextx][nexty] == 'O'){
					q.push(point(nextx, nexty));
				}
			}
		}
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (board[i][j] == 'O' && !visit[i][j]) board[i][j] = 'X';
			}
		}
	}
};
