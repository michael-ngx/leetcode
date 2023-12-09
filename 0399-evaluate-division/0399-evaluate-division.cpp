class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> map;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0], b = equations[i][1];
            map[a][b] = values[i];
            map[b][a] = 1/values[i];
        }
        // Load all possible calculations
        bfs(map);

        vector<double> result;
        for (auto& q : queries) {
            if (map.find(q[0]) == map.end() || map[q[0]].find(q[1]) == map[q[0]].end()) result.push_back(-1);
            else result.push_back(map[q[0]][q[1]]);
        }
        return result;
    }

    void bfs(unordered_map<string, unordered_map<string, double>>& map) {
        for (auto& start : map) {
            unordered_set<string> visited;
            stack<pair<string, double>> s;
            s.push({start.first, 1});
            while (!s.empty()) {
                auto p = s.top(); s.pop();
                string curr = p.first;
                double val = p.second;
                if (visited.find(curr) != visited.end()) continue;
                visited.insert(curr);
                
                map[start.first][curr] = val;
                map[curr][start.first] = 1/val;
                for (auto& pp : map[curr]) {
                    s.push({pp.first, val*pp.second});
                }
            }
        }
    }
};