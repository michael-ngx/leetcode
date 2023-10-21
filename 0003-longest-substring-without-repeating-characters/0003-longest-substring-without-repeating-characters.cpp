class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> count(128, 0);
        int i = 0, j = 0, res = 0;
        while (j != s.size()) {
            if (count[s[j]] > 0) count[s[i++]]--;
            else count[s[j++]]++;
            res = max(res, j - i);
        }
        return res; 
    }
};