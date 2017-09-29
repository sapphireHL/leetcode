class Solution {
public:
	unordered_map<string, unordered_map<string, double>> g;
	vector<double> res;

	void dfs(string from, string to, double& value, unordered_map<string, bool>& visit, bool& find) {
    		if(find) return;
		if (!g.count(from) || !g.count(to)) {
			return;
		}
		if (from == to) {
			res.push_back(value);
            		find = true;
			return;
		}
		visit[from] = true;
		for (auto i = g[from].begin(); i != g[from].end(); i++) {
			string next = i->first;
			double val = i->second;
			if (!visit[next]) {
				value *= val;
				dfs(next, to, value, visit, find);
				value /= val;
                		if(find) return;
			}
		}
	}

	vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
		for (int i = 0; i<equations.size(); i++) {
			string a = equations[i].first, b = equations[i].second;
			g[a][b] = values[i];
			g[b][a] = 1.0 / values[i];
			g[a][a] = 1.0;
			g[b][b] = 1.0;
		}
		for (int i = 0; i < queries.size(); i++) {
			string from = queries[i].first, to = queries[i].second;
			double value = 1.0;
			unordered_map<string, bool> visit;
            		bool find = false;
			dfs(from, to, value, visit, find);
            		if(res.size() <= i) res.push_back(-1);
		}
		return res;
	}
};
