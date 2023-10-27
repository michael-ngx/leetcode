class Solution {
public:
    string longestPalindrome(string s) {
        int best = 0, sz = s.size(), start;
        for (int i = 0; i < s.size(); i++) {
            int l = i - 1, r = i + 1;
            while (l >= 0 && s[l] == s[i]) l--;
            while (r < sz && s[r] == s[i]) r++;
            while (l >= 0 && r < sz && s[l] == s[r]) { l--; r++; }
            if (r - l - 1 > best) {
                best = r - l - 1;
                start = l + 1;
            }
        }
        return s.substr(start, best);
    }
};