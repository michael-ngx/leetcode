class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> v(26, 0);
        for (char c : s) v[c - 'a']++;
        for (char c : t) v[c - 'a']--;
        return all_of(v.begin(), v.end(), [](int i) { return i==0; });;
    }
};