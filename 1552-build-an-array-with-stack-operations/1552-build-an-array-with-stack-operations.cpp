class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int i = 0, j = 1;
        while (i != target.size()) {
            if (j == target[i]) {
                res.push_back("Push");
                i++;j++;
            } else {
                res.push_back("Push");
                res.push_back("Pop");
                j++;
            }
        }
        return res;
    }
};