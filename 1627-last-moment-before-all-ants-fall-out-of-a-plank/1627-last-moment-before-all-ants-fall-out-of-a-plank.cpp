class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        sort(left.begin(), left.end());
        sort(right.begin(), right.end());
        return max(left.empty() ? 0 : left.back(), right.empty() ? 0 : n - right.front());
    }
};