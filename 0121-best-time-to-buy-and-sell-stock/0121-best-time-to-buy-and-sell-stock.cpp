class Solution {
public:
    int maxProfit(vector<int>& p) {
        int buy = 0, sell = 0;
        int best = 0;
        for (; sell < p.size(); sell++) {
            if (p[sell] < p[buy]) buy = sell;
            best = max(p[sell] - p[buy], best);
        }
        return best;
    }
};