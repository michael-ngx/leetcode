class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j = 0;
        while (i < s.size()) {
            while (j + 1 < s.size() && s[j + 1] != ' ') j++;
            int next = j + 2;
            while (i < j) swap(s[i++], s[j--]);
            i = j = next;
        }
        return s;
    }
};