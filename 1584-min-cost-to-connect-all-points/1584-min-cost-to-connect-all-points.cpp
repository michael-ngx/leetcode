class Solution {
public:
    int calc(vector<vector<int>>& points, int a, int b) {
        return abs(points[a][0] - points[b][0]) + abs(points[a][1] - points[b][1]);
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        priority_queue<pair<int,int>> pq;
        int n = points.size();
        vector<bool> included(n, false);
        int res = 0;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto p = pq.top(); pq.pop();
            int dist = p.first;
            int id = p.second;
            if (included[id]) continue;
            included[id] = true;
            res += -dist;

            for (int i = 0; i < n; i++) {
                if (!included[i]) {
                    pq.push({-calc(points, id, i), i});
                }
            }
        }
        return res;
    }
};