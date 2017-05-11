class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int result = 0, n = M.size();
    	vector<bool> visited(n);
    	stack<int> s;
    	for (int i = 0; i < n; i++){
    		if (!visited[i]){
    			s.push(i);
    			while (!s.empty()){
    				int cur = s.top();
    				s.pop();
    				visited[cur] = true;
    				for (int j = 0; j < n; j++){
    					if (!visited[j] && M[cur][j] == 1)
    						s.push(j);
    				}
    			}
    			result++;
    		}
    	}
    	return result;
    }
};
