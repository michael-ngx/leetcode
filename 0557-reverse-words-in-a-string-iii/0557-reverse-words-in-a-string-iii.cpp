class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        string curr = "";
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != ' ') curr += s[i];
            else {
                result = curr + ' ' + result;
                curr = "";
            }
        }
        result = curr + ' ' + result;
        result.pop_back();
        return result;
    }
};